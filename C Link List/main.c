//
//  main.c
//  C Link List
//
//  Created by Saurav Nagpal on 12/24/13.
//  Copyright (c) 2013 $aur@v Nagp@l.
//

#include "LinkList.h"
#include <stdio.h>

void createIntegerLinkList(link_list* list);

int main(int argc, const char * argv[])
{
    link_list* list = newLinkList(link_list_int);
    createIntegerLinkList(list);
    return 0;
}

//Sample create a link list int
void createIntegerLinkList(link_list* list){
    int value = 2;
    int loopCount = 0;
    int loopLimit = 5;
    while(loopCount < loopLimit){
        addElementInLinkList(list, &value);
        value += loopLimit;
        loopCount++;
    }
}