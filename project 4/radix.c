//
//  main.c
//  radix
//
//  Created by Yousef Zoumot on 5/17/15.
//  Copyright (c) 2015 Yousef Zoumot. All rights reserved.
//


#include <assert.h>

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include "deque.h"

#define r 10

struct deque{
    int count;
    struct node *head;
};

struct node{
    int data;
    struct node *next, *prev;
};

int main(void)

{
    
    int i,j,k;
    
    DEQUE *dp;
    
    dp=createDeque();
    
    DEQUE *dX[r];
    
    assert(dp!=NULL);
    
    for(i=0;i<r;i++)
        
        dX[i]=createDeque();
    
    int x,max;
    
    max=0;
    
    while(scanf("%d",&x)>0)  //this while loop is used to take in int values that will later be returned in order
        
    {
        
        if(x>max)
            
            max=x;
        
        addFirst(dp,x);
        
    }
    
    max=ceil(log(max+1)/log(r));
    
    int sig,removed1,removed2;
    
    x=numItems(dp);
    
    for(i=0;i<max;i++) //these loops and nested loops are used to place values in order using a separate array
        
    {
        
        for(j=0;j<x;j++)
            
        {
            
            sig=(getLast(dp)/ (int) pow(10,i)) % 10;
            
            removed1=removeLast(dp);
            
            addFirst(dX[sig],removed1);
            
        }
        
        for(k=0;k<r;k++)
            
        {
            
            while(numItems(dX[k])>0)
                
            {
                
                removed2=removeLast(dX[k]);
                
                addFirst(dp,removed2);
                
            }
            
        }
        
    }
    
    while(numItems(dp)!=0) //this loop is used to print all values from the deque in order while simultaneously deleting all values from the deque so that the deque can be freed
        
    {
        
        printf("%d\n",(x=removeLast(dp)));
        
    }
    
    free(dp);
    
    return 0;
    
}