





void insert(struct list *pList, struct node *pNew, struct node *pPrev)
{
    assert(pList!= NULL && pNew!=NULL);
    
    if(pPrev==NULL)     //Case1(an empty list) & Case2(at the front)
    {
        pNew->next=pList->head;
        pList->head=pNew;
    }
    
    else{                //Case3(At the rear) & Case4(In the middle)
        pNew->next=pPrev->next;
        pPrev->next=pNew;
    }
    pList->count++;
}


void deleteNode(struct list *pList, struct node *pPrev)
{
    struct node *pDel;
    assert(pList !=NULL);
    if( pPrev==NULL)        //Case 1(the first node)
    {
        pDel=pList->head;
        pList->head=pDel->next;
    }
    else{     //Case2(the last nod)&Case3(in the middle)
        pDel=pPrev->next;
        pPrev->next=pDel->next;
    }
    free(pDel);
    pList->count--;
}


struct node{
    int data;
    struct node *left, *right;
};


void preorder(struct node *np)
{
    if(np==NULL)
        return;
    printf("%d/n", np->data);
    preorder(np->left);
    preorder(np->right);
    
}

void postorder(struct node *np)
{
    if(np==NULL)
        return;
    postorder(np->left);
    postorder(np->right);
    printf("%d/n", np->data);
}



int height(struct node *np)
{
    if(np==NULL)
        return 0;
    return 1+ max(height(np->left), height(np->right));
}


void destroy(struct node *np)
{   //O(n)
    if(np==NULL)
        return;
    destroy(np->left);
    destroy(np->right);
    free(np);
}


bool bsearch(struct node *np, int x)
{   //recursive implementation
    if(np == NULL)   //base case
        return false;
    if(x == np->data)
        return true;
    if(x < np->data)
        return bsearch(np->left, x);
    return bsearch(np->right, x);
        
}


bool bsearch(struct node *np, int x)
{   //iterative implementation O(h)
    
    while(np != NULL) //inverse of base case
    {
        if(x == np->data)
            return true;
        if(x < np->data)
            np=np->left;
        else
            np=np->right
    }
    return false;
}


int maximum(struct node *np)
{   //recursive O(h)
    assert(np!=NULL);
    if(np->right ==NULL)
        return np->data;
    return maximum(np->right);
}

int maximum(struct node *np)
{   //iterative O(h)
    assert(np!=NULL);
    while(np->right !=NULL)
        np=np->right;
    return np->data;
}

int minimum(struct node *np)
{   //recursive O(h)
    assert(np!=NULL);
    if(np->left ==NULL)
        return np->data;
    return minimum(np->left);
}

int minimum(struct node *np)
{   //iterative O(h)
    assert(np!=NULL);
    while(np->left !=NULL)
        np=np->left;
    return np->data;
}

void inorder(struct node *np)
{   //O(n)
    if(np==NULL)
        return;
    inorder(np->left);
    printf("%d\n", np->data);
    inorder(np->right);
}









