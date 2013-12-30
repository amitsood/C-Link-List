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

void releaseLinkList(link_list** ptrToList){
    list_struct_info* list = (*ptrToList)->link_list;
    list_struct_info* tmpList = NULL;
    while (list != NULL) {
        tmpList = list->next;
        free(list);
        list = tmpList;
    }
    *ptrToList = NULL;
}

//add the element to the list
void addElementInLinkList(link_list* listContainer, void* data){
    list_struct_info *list_element = (list_struct_info*) calloc(sizeof(list_struct_info), 1);
    list_struct_info* list = listContainer->link_list;
    list_element->data = data;
    list_element->next = NULL;
    switch (listContainer->list_element_count) {
        case 0:{
            listContainer->link_list = list_element;
            break;
        }
        default:{
             while (list->next != NULL) {
                 list = list->next;
             }
            list->next = list_element;
            break;
        }
    }
    listContainer->list_element_count++;
}