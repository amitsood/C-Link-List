//
//  main.c
//  C Link List
//
//  Created by Saurav Nagpal on 12/24/13.
//  Copyright (c) 2013 $aur@v Nagp@l.
//

#include "LinkList.h"
#include <stdio.h>

void createFloatLinkList(link_list* list);
void createIntegerLinkList(link_list* list);
void createDoubleLinkList(link_list* list);

int main(int argc, const char * argv[])
{
    link_list* int_list = newLinkList(link_list_int);
    link_list* float_list = newLinkList(link_list_float);
    link_list* double_list = newLinkList(link_list_double);
    int elementValue_int = 0;
    float elementValue_float = 0.0;
    double elementValue_double = 0.000;
    createIntegerLinkList(int_list);
    createFloatLinkList(float_list);
    createDoubleLinkList(double_list);
    getElementAtIndex(int_list, 2, &elementValue_int);
    getElementAtIndex(float_list, 3, &elementValue_float);
    getElementAtIndex(double_list, 4, &elementValue_double);
    printf("intValue:%d\n",elementValue_int);
    printf("floatValue:%f\n",elementValue_float);
    printf("floatValue:%f\n",elementValue_double);
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

void createFloatLinkList(link_list* list){
    float value = 5.0;
    float increment = 9.0;
    float loopCount = 0;
    float loopLimit = 5;
    while(loopCount < loopLimit){
        addElementInLinkList(list, &value);
        value += increment;
        loopCount++;
    }
}

void createDoubleLinkList(link_list* list){
    double value = 5.0000;
    double increment = 9.00000;
    float loopCount = 0;
    float loopLimit = 5;
    while(loopCount < loopLimit){
        addElementInLinkList(list, &value);
        value += increment;
        loopCount++;
    }
}