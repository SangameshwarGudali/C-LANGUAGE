struct dimension
{
    float width; 
    float height; 
    float depth; 
}; 

struct physical_info
{
    struct dimension item_dimensions; 
    float item_weight; 
}; 

struct airpod_item
{

    struct physical_info airpod_phys_info; 
}; 

int main()
{
    struct airpod_item my_airpod; 

    my_airpod.airpod_phys_info.item_dimensions.width = 5.0; 
    my_airpod.airpod_phys_info.item_dimensions.height = 2.0; 
    my_airpod.airpod_phys_info.item_dimensions.depth = 1.5; 
    my_airpod.airpod_phys_info.item_weight = 50.5; 
}
