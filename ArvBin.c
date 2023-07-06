#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// Linked List Node
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


/**
 * Traverse the binary tree in inorder fashion and store the values in a linked list.
 *
 * @param a - The binary tree
 * @param l - Pointer to the linked list
 */
void inorder (ABin a, LInt * l) {
    LInt p;
    if(a)
    { 
        inorder(a->dir,l);
        p=*l;
        *l=malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
        inorder(a->esq,l);
    }
}

/**
 * Traverse the binary tree in postorder fashion and store the values in a linked list.
 *
 * @param a - The binary tree
 * @param l - Pointer to the linked list
 */
void posorder (ABin a, LInt * l) {
    LInt p;
    if(a)
    { 
        p=*l;
        *l=malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
        posorder(a->dir,l);
        posorder(a->esq,l);
    }
}

/**
 * Traverse the binary tree in preorder fashion and store the values in a linked list.
 *
 * @param a - The binary tree
 * @param l - Pointer to the linked list
 */
void preorder (ABin a, LInt * l) {
    LInt p;
    if(a)
    { 
        preorder(a->dir,l);
        preorder(a->esq,l);
        p=*l;
        *l=malloc(sizeof(struct lligada));
        (*l)->valor=a->valor;
        (*l)->prox=p;
    }
}

/**
 * Calculate the height of the binary tree.
 *
 * @param a - The binary tree
 * @return The height of the binary tree
 */
int altura (ABin a) {
    int r=0,c,b;
    if (a!=NULL)
    {
        c=altura(a->esq);
        b=altura(a->dir);
        r+=1+(c>b?c:b);
    }
    return r;
}

/**
 * Create a copy of the binary tree.
 * 
 * @param a - The binary tree to be cloned
 * @return The cloned binary tree
 */
ABin cloneAB (ABin a) {
    ABin p;
    if (a==NULL) p=NULL;
    else
    {
        p=(ABin)malloc(sizeof(struct nodo));
        p->valor=a->valor;
        p->esq=cloneAB(a->esq);
        p->dir=cloneAB(a->dir);
    }    
    return p;
}

/**
 * Create a mirror image of the binary tree.
 * 
 * @param a - The binary tree to be mirrored
 */
void mirror (ABin *a) {
    ABin p;
    if (*a)
    {
        p=(*a)->dir;
        (*a)->dir=(*a)->esq;
        (*a)->esq=p;

        mirror(&((*a)->dir));
        mirror(&((*a)->esq));
    }
}

/* This function calculates the depth of a given value 'x' in a binary tree 'a'.
   It returns the depth if 'x' is found, otherwise it returns -1. */
int depth(ABin a, int x) {
    int m = -1, a1, a2;
    if (a) {
        if (a->valor == x)
            m = 1;
        else {
            a1 = depth(a->esq, x);
            a2 = depth(a->dir, x);
            if (a1 > 0 && a2 > 0)
                m = 1 + ((a1 < a2) ? a1 : a2);
            else if (a1 < 0 && a2 > 0)
                m = a2 + 1;
            if (a2 < 0 && a1 > 0)
                m = a1 + 1;
        }
    }
    return m;
}

/* This function frees the memory allocated for the binary tree 'a' and returns the number of nodes freed. */
int freeAB(ABin a) {
    int c = 0;
    if (a) {
        c += freeAB(a->esq);
        c += freeAB(a->dir);
        free(a);
        c++;
    }
    return c;
}

/* This function prunes the binary tree 'a' by removing all nodes at level 'l' and below.
   It returns the number of nodes pruned. */
int pruneAB(ABin *a, int l) {
    int c = 0;
    if (*a) {
        c += pruneAB(&((*a)->esq), l - 1);
        c += pruneAB(&((*a)->dir), l - 1);
        if (l <= 0) {
            free(*a);
            *a = 0;
            ++c;
        }
    }
    return c;
}

/* This function checks if two binary trees 'a' and 'b' are identical.
   It returns 1 if they are identical, otherwise it returns 0. */
int iguaisAB(ABin a, ABin b) {
    int verd = 0;
    if (a && b) {
        verd = (a->valor == b->valor) && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    }
    if (!a && !b)
        verd = 1;
    return verd;
}

/* This function returns a linked list containing all values at level 'n' in binary tree 'a' */
LInt nivelL(ABin a, int n) {
    LInt l1 = NULL, l2 = NULL, start;
    if (a) {
        if (n == 1) {
            l2 = malloc(sizeof(struct lligada));
            l2->valor = a->valor;
            l2->prox = NULL;
        } else {
            l1 = nivelL(a->dir, n - 1);
            l2 = nivelL(a->esq, n - 1);
            if (l2) {
                start = l2;
                for (; start && start->prox; start = start->prox);
                start->prox = l1;
            } else if (l1)
                l2 = l1;
        }
    }
    return l2;
}




/**
 * Returns the number of elements from the binary tree `a` at level `n` and stores them in the array `v`.
 * 
 * @param a The binary tree
 * @param n The level
 * @param v The array to store the elements
 * @return The number of elements stored in the array
 */
int nivelV (ABin a, int n, int v[]) {
  int li=0;
  if(a)
  {   
      if(n>1)
      {
      li+=nivelV(a->esq,n-1,v);
      li+=nivelV(a->dir,n-1,v+li);
      }
      if(n==1)
      {
          v[li]=a->valor;
          ++li;
      }
  }
  return li;
}

/**
 * Stores the elements of the binary tree `a` in the array `v` up to a maximum of `N` elements.
 * 
 * @param a The binary tree
 * @param v The array to store the elements
 * @param N The maximum number of elements to store
 * @return The number of elements stored in the array
 */
int dumpAbin (ABin a, int v[], int N) {
    int li=0;
    if(a && li<N)
    {
        li+=dumpAbin(a->esq,v,N);
        if(li<N)
        {
        v[li]=a->valor;
        ++li;
        }
        li+=dumpAbin(a->dir,v+li,N-li);
    }
    return li;
}







// Function to calculate the sum of values in a binary tree
// Returns the sum of values
int somasAcA2 (ABin a){
    int res = 0;
    if(a!=NULL) {
        res = a->valor;
        res += somasAcA2(a->esq) + somasAcA2(a->dir);
        a->valor = res;
    }
    return res;
}

// Function to update the value of the root node with the sum of values in the tree
// Returns the updated binary tree
ABin somasAcA (ABin a) {
    if(a)
    {
        a->valor=somasAcA2(a);    
    }

    return a;
}

// Function to count the number of leaf nodes in a binary tree
// Returns the count of leaf nodes
int contaFolhas (ABin a) {
    int i=0;
    if(a)
    {
        if(a->esq==0 && a->dir==0)
            ++i;
        else
        {
            i+=contaFolhas(a->esq);
            i+=contaFolhas(a->dir);
        }
    }    
    return i;
}

// Function to create a mirror image of a binary tree
// Returns the mirror image of the binary tree
ABin cloneMirror (ABin a) {
    ABin clone=NULL;
    if(a)
    {
        clone=(ABin)malloc(sizeof(struct nodo));
        clone->valor=a->valor;
        clone->esq=cloneMirror(a->dir);
        clone->dir=cloneMirror(a->esq);
    }
    return clone;
}

// Function to add a value to a binary tree in a sorted manner
// Updates the binary tree with the new value
// Returns 1 if the value already exists in the binary tree, 0 otherwise
int addOrd (ABin *a, int x) {
    int i=0;
    while(*a && !i)
    {
        if((*a)->valor>x)
            a=&((*a)->esq);
        else if((*a)->valor<x)
            a=&((*a)->dir);
        else i=1;
    }
    if(!i)
    {
        *a=(ABin)malloc(sizeof(struct nodo));
        (*a)->valor=x;
        (*a)->esq=NULL;
        (*a)->dir=NULL;
    }
    return i;
}

// Function to check if a value exists in a binary tree
// Returns 1 if the value exists, 0 otherwise
int lookupAB (ABin a, int x) {
    int i=0;
    while(a && !i)
    {
        if(a->valor>x)
            a=a->esq;
        else if(a->valor<x)
            a=a->dir;
        else i=1;
    }
    return i;
}


/* Returns the depth of the node with value x in the binary tree */
int depthOrd(ABin a, int x) {
    int i = 0, j = 0;
    while (a && !i) {
        if (a->valor > x)
            a = a->esq;
        else if (a->valor < x)
            a = a->dir;
        else
            i = 1; // Found the node with value x
        ++j;
    }
    if (!i)
        j = -1; // Node with value x not found
    return j;
}

/* Returns the largest value in the binary tree */
int maiorAB(ABin a) {
    while (a->dir)
        a = a->dir;
    return a->valor;
}

/* Removes the largest value in the binary tree */
void removeMaiorA(ABin *a) {
    ABin l;
    // Empty tree
    if (a) {
        while ((*a)->dir)
            a = &((*a)->dir);
        l = (*a)->esq;
        free(*a);
        *a = l;
    }
}

/* Returns the number of nodes in the binary tree that have a value greater than x */
int quantosMaiores(ABin a, int x) {
    int i = 0;
    if (a) {
        if (a->valor >= x) {
            if (a->valor > x)
                ++i;
            i += quantosMaiores(a->esq, x);
            i += quantosMaiores(a->dir, x);
        } else {
            i += quantosMaiores(a->dir, x);
        }
    }
    return i;
}

/* Returns 1 if the binary tree is a valid binary search tree within the given range [min, max], 0 otherwise */
int isProcura(ABin a, int min, int max) {
    int i = 1;
    if (a) {
        i = isProcura(a->esq, min, a->valor) && isProcura(a->dir, a->valor, max) && (a->valor >= min && a->valor <= max);
    }
    return i;
}


/**
 * Returns 1 if the given binary tree is a search tree, 0 otherwise.
 * @param a - The binary tree
 * @return 1 if a is a search tree, 0 otherwise
 */
int deProcura(ABin a) {
    int i = 1;
    ABin min = a, max = a;

    if (a) {
        // Find the minimum value in the tree
        while (min->esq)
            min = min->esq;

        // Find the maximum value in the tree
        while (max->dir)
            max = max->dir;

        // Check if the tree is a search tree
        i = isProcura(a, min->valor, max->valor);
    }

    return i;
}

/**
 * Inserts a node in the binary tree in the correct position.
 * @param p - The node to be inserted
 * @param a - The binary tree
 */
void insertOrd(ABin p, ABin *a) {
    while (*a) {
        if ((*a)->valor > p->valor)
            a = &((*a)->esq);
        else if ((*a)->valor < p->valor)
            a = &((*a)->dir);
    }
    *a = p;
}

/**
 * Converts a linked list to a binary tree.
 * @param l - The linked list
 * @param a - The binary tree pointer
 */
void listToBTree(LInt l, ABin *a) {
    ABin p;
    while (l) {
        p = malloc(sizeof(struct nodo));
        p->valor = l->valor;
        p->esq = NULL;
        p->dir = NULL;
        insertOrd(p, a);
        l = l->prox;
    }
}

/**
 * Prints the values of a binary tree in pre-order traversal.
 * @param p - The binary tree
 */
void printAb(ABin p) {
    if (p) {
        printf("%d  ", p->valor);
        printAb(p->esq);
        printAb(p->dir);
    }
}


// Structure for a binary tree node
struct nodo {
    int valor; // Value of the node
    struct nodo* esq; // Pointer to the left child
    struct nodo* dir; // Pointer to the right child
};

// Structure for a linked list node
struct ListNode {
    int valor; // Value of the node
    struct ListNode* prox; // Pointer to the next node
};

// Type definition for a binary tree
typedef struct nodo* ABin;

// Type definition for a linked list
typedef struct ListNode* LInt;

/**
 * Function to create a binary tree using user input
 * Returns the root of the binary tree
 */
ABin create() {
    ABin p;
    int x, less;
    printf("Enter data (-1 for no data): ");
    less = scanf("%d", &x);
    ++less;
    if (x == -1)
        return NULL;

    p = (ABin)malloc(sizeof(struct nodo));
    p->valor = x;

    printf("Enter left child of %d:\n", x);
    p->esq = create();

    printf("Enter right child of %d:\n", x);
    p->dir = create();

    return p;
}

/**
 * Function to print a linked list
 * Takes the head of the linked list as input
 */
void printLL(LInt l) {
    while (l) {
        printf("%d==>", l->valor);
        l = l->prox;
    }
    printf("NULL\n");
}

/**
 * Main function
 */
int main() {
    ABin p;
    LInt list = NULL, *l = &list;
    p = create();
    printAb(p);
    printf("\n\nLista: \n");
    posorder(p, l);
    printLL(*l);
    return 0;
}

