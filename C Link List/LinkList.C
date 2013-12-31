//
//  LinkList.C
//  C Link List
//
//  Created by Saurav Nagpal on 12/24/13.
//  Copyright (c) 2013 Global Logic. All rights reserved.
//

#include "LinkList.h"
#include "string.h"
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
    link_list_type          list_type;
};

/*************************
 *Function Declaration
 ************************/
list_struct* newListElement(link_list_type type,void* data);

/*************************
 *Function Defination
 ************************/

/*************************
 *Public Methods
 ************************/
//allocate the memory to list
link_list* newLinkList(link_list_type type){
    link_list* newList = (link_list*) calloc(sizeof(link_list), 1);
    newList->link_list = NULL;
    newList->list_element_count = 0;
    newList->list_type = type;
    return newList;
}

//release the link list memory
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

//return the element count
long getElementCount(link_list* list){
    return list->list_element_count;
}

//add the element to the list
void addElementInLinkList(link_list* listContainer, void* data){
    list_struct* list = listContainer->link_list;
    list_struct* newElement = newListElement(listContainer->list_type, data);
    switch (listContainer->list_element_count) {
        case 0:{
            listContainer->link_list = newElement;
            break;
        }
        default:{
             while (list->next != NULL) {
                 list = list->next;
             }
            list->next = newElement;
            break;
        }
    }
    listContainer->list_element_count++;
}

//Delete a element in a link list
void deleteElementInLinkList(link_list* listContainer, void* data){
    list_struct_info* list = listContainer->link_list;
    while (list->next != NULL) {
        list = list->next;
    }
}

/*************************
 *Private Methods
 ************************/
list_struct* newListElement(link_list_type type,void* data){
    list_struct *list_element = (list_struct*) calloc(sizeof(list_struct), 1);
    switch (type) {
        case link_list_int:{
            int* newData = (int*)calloc(sizeof(int), 1);
            *newData =*((int*)data);
            list_element->data = newData;
            break;
        }
        case link_list_double:{
            double* newData = (double*)calloc(sizeof(double), 1);
            *newData =*((double*)data);
            list_element->data = newData;
            break;
        }
        case link_list_float:{
            float* newData = (float*)calloc(sizeof(float), 1);
            *newData =*((float*)data);
            list_element->data = newData;
            break;
        }
        case link_list_string:{
            char* newData = (char*)calloc(sizeof(char), strlen((char*)data));
            *newData =*((char*)data);
            list_element->data = newData;
            break;
        }
        case link_list_void:{
            list_element->data = data;
            break;
        }
    }
    list_element->next = NULL;
    return list_element;
}