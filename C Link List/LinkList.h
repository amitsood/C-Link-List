//
//  LinkList.h
//  C Link List
//
//  Created by Saurav Nagpal on 12/24/13.
//  Copyright (c) 2013 Global Logic. All rights reserved.
//

#ifndef C_Link_List_LinkList_h
#define C_Link_List_LinkList_h

typedef struct link_list_struct_info link_list;

link_list* newLinkList();
void deallocLinkList(link_list** list);
void addElementInLinkList(link_list* list, void* data);

#endif
