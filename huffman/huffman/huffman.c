//
//  main.c
//  huffman
//
//  Created by Yousef Zoumot on 5/28/15.
//  Copyright (c) 2015 Yousef Zoumot. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"

int counts[257];    //#of each character
struct tree *leaves[257]; //contains all children
struct tree *heap[257];  //your priority queue
int counter=0;

#define p(x) (((x)-1)/2)  //returns parent location
#define l(x) ((x)*2+1)  //returns left child location
#define r(x) ((x)*2+2)  //returns right child location


void insert(struct tree *np)
{
    int indx=counter++;
    while(getData(np) < getData(heap[p(indx)]))
    {
        heap[indx]=heap[p(indx)];
        indx=p(indx);
    }
    heap[indx]=np;
    counter++;
}

struct tree *delete(void)
{
    int flag=0;
    struct tree *np, *child, *temp, *min;
    min=heap[0];
    np=heap[counter];
    int indx=counter++;
    np=heap[counter--];
    while(l(indx)<counter)
    {
        child=heap[l(indx)];
        if(r(indx)<counter && getData(heap[l(indx)]) > getData(heap[r(indx)]))
        {
            child=heap[r(indx)];
            flag++;
        }
        if(getData(np) > getData(child))
        {
            temp=heap[indx];
            heap[indx]=child;
            child=temp;
            if(flag==0)
                indx=l(indx);
            else
                indx=r(indx);
            
        }
        else
            break;
    }
    heap[indx]=np;
    return min;
}

void printcode( struct tree *np){       //O(n) prints either a 0 or 1 depending on the parent's encoding
    assert(np !=NULL);
    struct tree *parent;
    if((parent=getParent(np))==NULL)
        return;
    printcode(parent);
    if(getLeft(parent)==np)
        printf("1");
    else
        printf("0");
    return;
}
    



int main(int argc, const char * argv[]) {
    
    assert(argc == 3); //makes sure three arguments are passed in
    
    
    for(int i=0; i<257; i++)  //initializes all data
    {
        counts[i]=0;
        leaves[i]=NULL;
        heap[i]=NULL;
    }
    
    
    FILE *fp;
    
    fp= fopen(argv[1], "rb");  //opens input file
    
    
    int character;
    
    while((character=getc(fp)) != EOF)  //this loop counts the occurences of each character
        counts[character]++;
    
        fclose(fp); //closes input file
    
    for(int j=0; j<257; j++)    //creates leaves and places them into heap
    {
        if(counts[j] != 0)
        {
            leaves[j]=createTree(counts[j], NULL, NULL);
            insert(leaves[j]);
        }
    }
    
    
    leaves[256]=createTree(0, NULL, NULL); //creates EOF
    insert(leaves[256]);                //inserts EOF into heap
    struct tree *l, *r;
    while(counter>1)        //deletes from heap and assigns the sum of the two as a root and sets its left and right child
    {
        l=delete();
        r=delete();
        struct tree *new= createTree(getData(r)+getData(l), l, r);
        insert(new);
    }
    
    for(int h=0; h<257; h++)
    {
        if(leaves[h] != NULL)
        {
            if(isprint(h))      //checks if it is printable
                {
                printf("%c", h);
                printf("%i", counts[h]);
                    printcode(leaves[h]);
                }
            else{               //else prints octal instead
                printf("%03o", h);
                printf("%i", counts[h]);
                printcode(leaves[h]);
                }
        }
    }
    
    
  
    
    
}
