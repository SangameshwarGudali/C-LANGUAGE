/* 
    @goal:  To create a new instance of a singly linked list. 
            This function accepts no input. 
            Dynamically allocates a memory to head node. 
            Initialises 'data' member to -1 and 'next' member to NULL 
            and returns the head node. Therefore, the type of return 
            value is struct node* 
*/ 
struct node* create_list(void); 

/* 
    @goal:  To insert a new data element at the starting position of the list 
    @param1: p_head_node: struct node*: Address of head node of a list to which 
                                        new data must be added at the start 
    (ज्या लिस्ट च्या सुरुवातीला डेटा अॅड करायचा आहे, त्या लिस्ट च्या हेड नोड चा अडरेस स्टोर 
    करण्यासाठी पॉइंटर)
    @param2: new_data: int: value of data to be added 
    (जो डेटा अॅड करायचा आहे त्याची वॅल्यू)
    @return: status of the function 
    (स्टेटस ऑफ function)
*/ 
int insert_at_start(struct node* p_head_node, int new_data); 

/* 
    @goal: To insert new data element at the ending position of the list 
    @param1: pointer containing address of the head node of the list to which 
             the new data must be added at the end
    ज्या लिस्ट च्या एण्ड ला डेटा अॅड करायचा आहे, त्याच्या हेड नोड चा अॅड्रेस ठेवण्यासाठी 
    पोइंटर
    @param2: value of data to be added 
    डेटा वॅल्यू
*/ 
int insert_at_end(struct node* p_head_node, int new_data); 

/* 
    @goal: To insert data at position WHICH SUCCEEDS the poistion of 
            given data 
    @param1: pointer to store the address of the head node of a list 
            to which insertion must be made 
    (ज्या लिस्ट मध्ये डेटा इन्सर्ट करायचा आहे, त्याच्या हेड नोड चा अॅड्रेस स्टोर करण्यासाठी पोइंटर)
    
    @param2: Value of existing data after which the new data must be added 
    (लिस्ट मधल्या ज्या डेटा वॅल्यू नंतर नवीन डेटा अॅड करायचा आहे, ती वॅल्यू स्टोर करण्यासाठी 
    varible)
    @param3: new data value 
    (नवीन डेटा वॅल्यू)
    @return: status of the function 
*/ 
int insert_after_data(struct node* p_head_node, int e_data, int new_data); 

/* 
     @goal: To insert data at position WHICH PRECEDS  the poistion of 
            given data 
    @param1: pointer to store the address of the head node of a list 
            to which insertion must be made 
    (ज्या लिस्ट मध्ये डेटा इन्सर्ट करायचा आहे, त्याच्या हेड नोड चा अॅड्रेस स्टोर करण्यासाठी पोइंटर)
    
    @param2: Value of existing data before which the new data must be added 
    (लिस्ट मधल्या ज्या डेटा वॅल्यू आधी नवीन डेटा अॅड करायचा आहे, ती वॅल्यू स्टोर करण्यासाठी varible)
    @param3: new data value 
    (नवीन डेटा वॅल्यू)
    @return: status of the function 
*/ 
int insert_before_data(struct node* p_head_node, int e_data, int new_data); 
