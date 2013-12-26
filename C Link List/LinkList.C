//
//  LinkList.C
//  C Link List
//
//  Created by Saurav Nagpal on 12/24/13.
//  Copyright (c) 2013 Global Logic. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>

/*************************
 *Variable Declaration
 ************************/
typedef struct list_struct_info list_struct;

/*************************
 *Variable Defination
 ************************/
struct list_struct_info{
    void*              data;
    list_struct*       next;
};

struct link_list_struct_info{
    list_struct_info*       link_list;
    long                    list_element_count;
};

/*************************
 *Function Defination
 ************************/

//allocate the memory to list
link_list* newLinkList(){
    link_list* newList = (link_list*) calloc(sizeof(link_list), 1);
    newList->link_list = NULL;
    newList->list_element_count = 0;
    return newList;
}

//add the element to the list
void addElementInLinkList(link_list* list, void* data){
    
    link_list *list_element = (link_list*) calloc(sizeof(link_list), 1);
    switch (list->list_element_count) {
        case 0:{
            break;
        }
        default:
            break;
    }
}