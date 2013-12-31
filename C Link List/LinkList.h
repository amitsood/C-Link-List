//
//  LinkList.h
//  C Link List
//
//  Created by Saurav Nagpal on 12/24/13.
//  Copyright (c) 2013 Global Logic. All rights reserved.
//

#ifndef C_Link_List_LinkList_h
#define C_Link_List_LinkList_h

typedef enum link_list_type_enum{
    link_list_int,
    link_list_float,
    link_list_double,
    link_list_string,
    link_list_void // if specify then memory handling at developer end
}link_list_type;

typedef struct link_list_struct_info link_list;

link_list* newLinkList(link_list_type type);
void releaseLinkList(link_list** list);
long getElementCount(link_list* list);
void addElementInLinkList(link_list* list, void* data);
void deleteElementInLinkList(link_list* list, void* data);
void deleteElementAtIndexInLinkList(int index);

#endif
