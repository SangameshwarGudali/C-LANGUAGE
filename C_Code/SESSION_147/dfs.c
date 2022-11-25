#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

#define SUCCESS             1 

#define G_VERTEX_EXISTS     2 
#define G_EDGE_EXISTS       3 
#define G_VERTEX_INVALID    4 
#define G_EDGE_INVALID      5 

#define LIST_EMPTY          6 

#define WHITE   0 
#define GRAY    1 
#define BLACK   2 

struct hnode
{
    int v; 
    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode
{
    int v; 
    int color; 
    struct hnode* ph_list; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct graph
{
    struct vnode* pv_list; 
    size_t nr_vertices; 
    size_t nr_edges; 
}; 

struct edge
{
    int v_start; 
    int v_end; 
}; 

/* Graph management -> Interface routines */ 
struct graph* create_graph(void); 
int add_vertex(struct graph *g, int v); 
int remove_vertex(struct graph* g, int v); 
int add_edge(struct graph* g, int v_start, int v_end); 
int remove_edge(struct graph* g, int v_start, int v_end); 
void print_graph(struct graph* g, const char* msg); 
int destroy_graph(struct graph* g); 
void reset(struct graph* g); 
void dfs(struct graph* g); 

/* Graph auxillaru routine */ 
void dfs_visit(struct graph* g, struct vnode* pu); 

/* Graph management -> vlist management -> Interface routines */ 
struct vnode* v_create_list(void); 
int v_insert_end(struct vnode* pv_list, int v); 

/* Graph management -> vlist management -> Auxillary routines */ 
void v_generic_insert(struct vnode* p_beg, struct vnode* p_mid, struct vnode* p_end); 
void v_generic_delete(struct vnode* p_delete_node); 
struct vnode* v_search_node(struct vnode* pv_list, int v); 
struct vnode* v_get_node(int v); 

/* Graph management -> hlist management -> Interface routines  */ 
struct hnode* h_create_list(void); 
int h_insert_end(struct hnode* ph_list, int v); 

/* Graph management -> hlist management -> Auxillary Routines */ 
void h_generic_insert(struct hnode* p_beg, struct hnode* p_mid, struct hnode* p_end); 
void h_generic_delete(struct hnode* p_delete_node); 
struct hnode* h_search_node(struct hnode* ph_list, int v); 
struct hnode* h_get_node(int v); 

/* Auxillary function */ 
void* xcalloc(size_t nr_elements, size_t size_per_element); 

int main(void)
{
    int V[] = {1, 2, 3, 4, 5, 6}; 
    struct edge E[] = { {1, 2}, {1, 6}, {2, 6}, 
                        {2, 5}, {2, 3}, {3, 5}, 
                        {3, 4}, {4, 5}, {5, 6}
                    }; 
    int i; 
    int status; 
    struct graph* g = NULL; 

    g = create_graph(); 

    for(i = 0; i < sizeof(V)/sizeof(V[0]); ++i)
        assert((status = add_vertex(g, V[i])) == SUCCESS);  

    for(i = 0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        status = add_edge(g, E[i].v_start, E[i].v_end); 
        assert(status == SUCCESS); 
    }
    print_graph(g, "Initial state:"); 

    puts("DFS on initial state:"); 
    dfs(g); 

    status = remove_edge(g, 1, 6); 
    assert(status == SUCCESS); 
    status = remove_edge(g, 4, 5); 
    assert(status == SUCCESS);
    print_graph(g, "After removing (1, 6) and (4, 5)"); 

    status = remove_vertex(g, 2); 
    assert(status == SUCCESS); 
    print_graph(g, "After removing vertex 2");

    status = add_vertex(g, 7); 
    assert(status == SUCCESS); 

    status = add_edge(g, 7, 1); 
    assert(status == SUCCESS); 

    status = add_edge(g, 7, 4); 
    assert(status == SUCCESS); 
    print_graph(g, "After adding vertex 7 and edges (7, 1) and (7, 4)");

    status = destroy_graph(g); 
    g = NULL; 

    return (EXIT_SUCCESS); 
}

struct graph* create_graph(void)
{
    struct graph* g = NULL; 

    g = (struct graph*)xcalloc(1, sizeof(struct graph)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
}

int add_vertex(struct graph *g, int v)
{
    struct vnode* pv_new_node = NULL; 
    struct vnode* pv_ret = NULL; 
    int status; 

    pv_ret = v_search_node(g->pv_list, v); 
    if(pv_ret != NULL)
        return (G_VERTEX_EXISTS); 

    status = v_insert_end(g->pv_list, v); 
    assert(status == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
}

int remove_vertex(struct graph* g, int v)
{
    struct vnode* pv_delete_vertex = NULL; 
    struct vnode* pv_adj_vertex = NULL; 
    struct hnode* ph_run = NULL; 
    struct hnode* ph_run_next = NULL; 
    struct hnode* ph_delete_node_in_adj_list = NULL; 

    pv_delete_vertex = v_search_node(g->pv_list, v); 
    if(pv_delete_vertex == NULL)
        return (G_VERTEX_INVALID); 

    ph_run = pv_delete_vertex->ph_list->next; 
    while(ph_run != pv_delete_vertex->ph_list)
    {
        ph_run_next = ph_run->next; 
        pv_adj_vertex = v_search_node(g->pv_list, ph_run->v); 
        assert(pv_adj_vertex != NULL); 
        ph_delete_node_in_adj_list = h_search_node(pv_adj_vertex->ph_list, v); 
        assert(ph_delete_node_in_adj_list != NULL); 
        h_generic_delete(ph_delete_node_in_adj_list); 
        free(ph_run); 
        g->nr_edges--; 
        ph_run = ph_run_next; 
    }

    free(pv_delete_vertex->ph_list); 
    v_generic_delete(pv_delete_vertex); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
}

int add_edge(struct graph* g, int v_start, int v_end)
{  
    struct vnode* pv_start = NULL; 
    struct vnode* pv_end = NULL;
    int status; 

    pv_start = v_search_node(g->pv_list, v_start); 
    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_start == NULL || pv_end == NULL)
        return (G_VERTEX_INVALID); 

    status = h_insert_end(pv_start->ph_list, v_end); 
    assert(status == SUCCESS); 

    status = h_insert_end(pv_end->ph_list, v_start); 
    assert(status == SUCCESS); 

    g->nr_edges++; 

    return (SUCCESS); 
}

int remove_edge(struct graph* g, int v_start, int v_end)
{
    struct vnode* pv_start = NULL; 
    struct vnode* pv_end = NULL; 
    struct hnode* ph_start_in_end = NULL; 
    struct hnode* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_start == NULL || pv_end == NULL)
        return (G_VERTEX_INVALID); 

    ph_start_in_end = h_search_node(pv_end->ph_list, v_start); 
    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start == NULL || ph_start_in_end == NULL)
        return (G_EDGE_INVALID); 

    h_generic_delete(ph_end_in_start); 
    h_generic_delete(ph_start_in_end); 

    g->nr_edges -= 1; 

    return (SUCCESS); 
}

void print_graph(struct graph* g, const char* msg)
{
    struct vnode* pv_run = NULL; 
    struct hnode* ph_run = NULL; 

    if(msg)
        puts(msg); 
    printf("|V|=%llu, |E|=%llu\n", g->nr_vertices, g->nr_edges); 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next)
    {
        printf("[%d]\t<->\t", pv_run->v);
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next)
            printf("[%d]<->", ph_run->v); 
        puts("[END]"); 
    }
}

int destroy_graph(struct graph* g)
{
    struct vnode* pv_run = NULL, *pv_run_next = NULL; 
    struct hnode* ph_run = NULL, *ph_run_next = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run_next)
    {
        pv_run_next = pv_run->next; 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run_next)
        {
            ph_run_next = ph_run->next; 
            free(ph_run); 
        }
        free(pv_run->ph_list); 
        free(pv_run); 
    }

    free(g->pv_list); 
    free(g); 
    g = NULL;  

    return (SUCCESS); 
}

void dfs(struct graph* g)
{
    struct vnode* pv_run = NULL; 

    reset(g); 
    printf("[START]<->"); 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next)
        if(pv_run->color == WHITE)
            dfs_visit(g, pv_run); 
    puts("[END]"); 
}

void reset(struct graph* g)
{
    struct vnode* pv_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next)
        pv_run->color = WHITE; 
}

/* Graph auxillary routine */ 

void dfs_visit(struct graph* g, struct vnode* pu)
{
    struct vnode* pv_in_adj = NULL; 
    struct hnode* ph_run = NULL; 

    printf("[%d]<->", pu->v); 
    pu->color = GRAY; 

    for(ph_run = pu->ph_list->next; ph_run != pu->ph_list; ph_run = ph_run->next)
    {
        pv_in_adj = v_search_node(g->pv_list, ph_run->v); 
        if(pv_in_adj->color == WHITE)
            dfs_visit(g, pv_in_adj); 
    }

    pu->color = BLACK; 
}

/* Graph management -> vlist management -> Interface routines */ 
struct vnode* v_create_list(void)
{
    struct vnode* pv_list = NULL; 

    pv_list = (struct vnode*)xcalloc(1, sizeof(struct vnode)); 
    pv_list->v = -1; 
    pv_list->ph_list = NULL; 
    pv_list->prev = pv_list; 
    pv_list->next = pv_list; 

    return (pv_list); 
}

int v_insert_end(struct vnode* pv_list, int v)
{
    v_generic_insert(pv_list->prev, v_get_node(v), pv_list); 
    return (SUCCESS); 
}

/* Graph management -> vlist management -> Auxillary routines */ 
void v_generic_insert(struct vnode* p_beg, struct vnode* p_mid, struct vnode* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void v_generic_delete(struct vnode* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
    p_delete_node = NULL; 
}

struct vnode* v_search_node(struct vnode* pv_list, int v)
{
    struct vnode* pv_run = NULL; 

    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next)
        if(pv_run->v == v)
            return (pv_run); 

    return (NULL); 
}

struct vnode* v_get_node(int v)
{
    struct vnode* pv_node = NULL; 

    pv_node = (struct vnode*)xcalloc(1, sizeof(struct vnode)); 
    pv_node->v = v; 
    pv_node->ph_list = h_create_list(); 

    return (pv_node); 
}

/* Graph management -> hlist management -> Interface routines  */ 
struct hnode* h_create_list(void)
{
    struct hnode* ph_list = NULL; 

    ph_list = h_get_node(-1); 
    ph_list->prev = ph_list; 
    ph_list->next = ph_list; 

    return (ph_list); 
}

int h_insert_end(struct hnode* ph_list, int v)
{
    h_generic_insert(ph_list->prev, h_get_node(v), ph_list); 
    return (SUCCESS); 
}

/* Graph management -> hlist management -> Auxillary Routines */ 
void h_generic_insert(struct hnode* p_beg, struct hnode* p_mid, struct hnode* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void h_generic_delete(struct hnode* p_delete_node)
{   
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
    p_delete_node = NULL; 
}

struct hnode* h_search_node(struct hnode* ph_list, int v)
{
    struct hnode* ph_run = NULL; 

    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next)
        if(ph_run->v == v)
            return (ph_run); 

    return (NULL); 
}

struct hnode* h_get_node(int v)
{
    struct hnode* ph_node = NULL; 

    ph_node = (struct hnode*)xcalloc(1, sizeof(struct hnode)); 
    ph_node->v = v; 

    return (ph_node); 
}

void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL; 

    p = calloc(nr_elements, size_per_element); 
    if(p == NULL)
    {
        fprintf(stderr, "Calloc:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
}