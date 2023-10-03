
//  deque.c
//  radix
//
//  Created by Yousef Zoumot on 5/17/15.
//  Copyright (c) 2015 Yousef Zoumot. All rights reserved.
//

#include <stdio.h>

#include <assert.h>

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include "deque.h"

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct deque{
    int count;
    struct node *head;
};



DEQUE *createDeque(void){
    
    DEQUE *dp;
    
    dp=malloc(sizeof(struct deque));
    
    dp->head= malloc(sizeof(struct node));
    
    assert(dp!=NULL && dp->head!=NULL);
    
    dp->head->next=dp->head;
    
    dp->head->prev=dp->head;
    
    dp->count=0;
    
    return dp;
    
}



void destroyDeque(DEQUE *dp){
    
    assert(dp!=NULL);
    
    struct node *np, *next;
    
    np=dp->head;
    
    do{  //this do while loop will go through and free all the values in the deque
        
        next=np;
        
        np=np->next;
        
        free(next);
        
    }while(np!=dp->head);
    
    free(dp);
    
}



int numItems(DEQUE *dp){
    
    assert(dp!=NULL);
    
    return dp->count;
    
}

void addFirst(DEQUE *dp, int x){
    
    assert(dp!=NULL);
    
    struct node *np;
    
    np=malloc(sizeof(struct node));
    
    assert(np!=NULL);
    
    dp->head->next->prev=np;
    
    np->next=dp->head->next;
    
    np->prev=dp->head;
    
    dp->head->next=np;
    
    np->data=x;
    
    dp->count++;
    
    return;
    
}



void addLast(DEQUE *dp, int x){
    
    assert(dp!=NULL);
    
    struct node *np;
    
    np=malloc(sizeof(struct node));
    
    assert(np!=NULL);
    
    np->next=dp->head;
    
    np->prev=dp->head->prev;
    
    dp->head->prev->next=np;
    
    dp->head->prev=np;
    
    np->data=x;
    
    dp->count++;
    
    return;
    
    
}

int removeFirst(DEQUE *dp){
    
    assert(dp!=NULL);
    
    int data;
    
    struct node *np;
    
    np=dp->head->next;
    
    data=np->data;
    
    dp->head->next=dp->head->next->next;
    
    dp->head->next->prev=dp->head;
    
    free(np);
    
    dp->count--;
    
    return data;
    
}



int removeLast(DEQUE *dp){
    
    assert(dp!=NULL);
    
    int data;
    
    struct node *np;
    
    np=dp->head->prev;
    
    data=np->data;
    
    dp->head->prev=dp->head->prev->prev;
    
    dp->head->prev->next=dp->head;
    
    free(np);
    
    dp->count--;
    
    return data;
    
    
}

int getFirst(DEQUE *dp){
    
    assert(dp!=NULL);
    
    return dp->head->next->data;
    
}



int getLast(DEQUE *dp){
    
    assert(dp!=NULL);
    
    return dp->head->prev->data;
    
    
}