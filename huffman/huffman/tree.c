//
//  tree.c
//  huffman
//
//  Created by Yousef Zoumot on 5/21/15.
//  Copyright (c) 2015 Yousef Zoumot. All rights reserved.
//


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
};

static void detach(struct tree *child)
{
    if(child->parent != NULL)
    {
        if(child->parent->right == child)
            child->parent->right = NULL;
        else if(child->parent->left == child)
            child->parent->left = NULL;
    }
    return;
}

struct tree *createTree(int data, struct tree *left, struct tree *right)
{
    struct tree *tp;
    tp=malloc(sizeof(struct tree));
    assert(tp != NULL);
    tp->data = data;
    tp->left= left;
    tp->right=right;
    if(left != NULL){
        detach(tp->left);
        tp->left->parent = tp;}
    if(right != NULL){
        detach(tp->right);
        tp->right->parent = tp;}
    return tp;
}

void destroyTree(struct tree *root)
{
    if(root==NULL)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

int getData(struct tree *root)
{
    assert(root !=NULL);
    return root->data;
}

struct tree *getLeft(struct tree *root)
{
    assert(root !=NULL);
    return root->left;
}

struct tree *getRight(struct tree *root)
{
    assert(root !=NULL);
    return root->right;
}

struct tree *getParent(struct tree *root)
{
    assert(root !=NULL);
    return root->parent;
}

void setLeft(struct tree *root, struct tree *left)
{
    if(root->left !=NULL)
        detach(root->left);
    
    root->left=left;
    root->left->parent=root;
    
    
}

void setRight(struct tree *root, struct tree *right)
{
    if(root->right !=NULL)
        detach(root->right);
    
    root->right=right;
    root->right->parent=root;
}