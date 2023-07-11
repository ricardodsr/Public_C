#include <stdlib.h>
#include <stdio.h>

typedef struct lligada {
    int valor; // Represents the value stored in the node
    struct lligada *prox; // Represents the pointer to the next node
} *LInt; // Represents a pointer to the structure

// Function to calculate the length of the linked list
int length(LInt l) {
    int i = 0; // Counter variable to keep track of the length
    while (l) { // Iterate through the linked list until NULL is reached
        ++i; // Increment the counter
        l = l->prox; // Move to the next node
    }
    return i; // Return the length
}

// Function to free the memory occupied by the linked list
void freeL(LInt l) {
    LInt *l1; // Pointer to the next node
    while (l) { // Iterate through the linked list until NULL is reached
        l1 = &(l->prox); // Assign the address of the next node to l1
        free(l); // Free the current node
        l = *l1; // Move to the next node
    }
}

// Function to print the values of the linked list
void imprimeL(LInt x) {
    while (x) { // Iterate through the linked list until NULL is reached
        printf("%d\n", x->valor); // Print the value of the current node
        x = x->prox; // Move to the next node
    }
}

// Function to reverse the linked list
LInt reverseL(LInt l) {
    LInt l2, l1 = NULL; // l2 points to the next node, l1 points to the previous node
    while (l) { // Iterate through the linked list until NULL is reached
        l2 = l->prox; // Store the next node in l2
        l->prox = l1; // Reverse the pointer of the current node to the previous node
        l1 = l; // Move l1 to the current node
        l = l2; // Move l to the next node
    }
    return l1; // Return the new head of the reversed linked list
}

// Function to insert a value in the linked list in ascending order
void insertOrd(LInt *l, int x) {
    LInt new; // Represents the new node to be inserted
    while (*l && (*l)->valor < x) { // Iterate through the linked list until the appropriate position is found
        l = &((*l)->prox); // Move to the next node
    }
    new = (LInt)malloc(sizeof(struct lligada)); // Allocate memory for the new node
    new->valor = x; // Set the value of the new node
    new->prox = *l; // Set the next pointer of the new node to the current node
    *l = new; // Update the previous node's next pointer to the new node
}

int removeOneOrd (LInt *l, int x){
    LInt p; // Create a pointer to a linked list node
    int t=1; // Initialize a variable t with the value 1
    while(*l && (*l)->valor!=x) // Loop until the end of the list or until the value is found
       l=&((*l)->prox); // Update the pointer to the next node

    if(*l){ // If the value was found
        p=(*l)->prox; // Assign the next node to p
        free(*l); // Free the memory of the current node
        *l=p; // Update the pointer to skip the current node
        t=0; // Set t to 0 to indicate that the value was found and removed
    }

    return t; // Return the value of t
}

// Function to merge two linked lists in ascending order
void merge(LInt *r, LInt l1, LInt l2) {
    LInt new; // Create a new node to store the merged list

    // Iterate until either l1 or l2 becomes null
    while (l1 || l2) {
        if ((!l1) || (l2 && l1->valor > l2->valor)) {
            // If l1 is null or l2 has a smaller value, create a new node
            // and assign l2's value to it. Set the next pointer to NULL.
            new = (LInt)malloc(sizeof(struct lligada));
            new->valor = l2->valor;
            new->prox = NULL;

            // Assign the new node to the current pointer in the merged list.
            *r = new;

            // Move the current pointer to the next node.
            r = &(new->prox);

            // Move l2 to the next node in its list.
            l2 = l2->prox;
        } else {
            // If l2 is null or l1 has a smaller value, create a new node
            // and assign l1's value to it. Set the next pointer to NULL.
            new = (LInt)malloc(sizeof(struct lligada));
            new->valor = l1->valor;
            new->prox = NULL;

            // Assign the new node to the current pointer in the merged list.
            *r = new;

            // Move the current pointer to the next node.
            r = &(new->prox);

            // Move l1 to the next node in its list.
            l1 = l1->prox;
        }
    }
}

// Simplified version of the merge function
void merge1(LInt *r, LInt l1, LInt l2) {
    // Iterate until either l1 or l2 becomes null
    while (l1 || l2) {
        if ((!l1) || (l2 && l1->valor > l2->valor)) {
            // If l1 is null or l2 has a smaller value, assign l2 to the
            // current pointer in the merged list.
            *r = l2;

            // Move the current pointer to the next node.
            r = &(l2->prox);

            // Move l2 to the next node in its list.
            l2 = l2->prox;
        } else {
            // If l2 is null or l1 has a smaller value, assign l1 to the
            // current pointer in the merged list.
            *r = l1;

            // Move the current pointer to the next node.
            r = &(l1->prox);

            // Move l1 to the next node in its list.
            l1 = l1->prox;
        }
    }
}


/**
 * Split the linked list into two separate lists based on a given value.
 * Elements with a value less than the given value will be in the list *mx,
 * while elements with a value greater than or equal to the given value will be in the list *Mx.
 *
 * @param l - The input linked list.
 * @param x - The value to split the list.
 * @param mx - Pointer to the head of the list *mx.
 * @param Mx - Pointer to the head of the list *Mx.
 */
void splitMS(LInt l, int x, LInt *mx, LInt *Mx) {
    while (l) {
        if (l->valor < x) {
            *mx = l;
            mx = &((*mx)->prox);
        } else {
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    *mx = 0;
    *Mx = 0;
}

/**
 * Splits a linked list in half and returns the first half.
 * If the list is empty or has only one element, returns NULL.
 *
 * @param l - Pointer to the head of the linked list.
 * @return Pointer to the head of the first half of the linked list.
 */
LInt parteAmeio(LInt *l) {
    // Calculate the length of the linked list
    int len = length(*l);

    // Calculate the index of the middle element
    int i = len / 2;

    // Pointers to track the head and tail of the first half of the linked list
    LInt p = *l;
    LInt u = *l;

    // If the linked list has only one element or is empty, return NULL
    if (i == 0) {
        *l = u;
        return NULL;
    }

    // Traverse to the middle element of the linked list
    for (int j = 0; j < i; ++j)
        p = p->prox;

    // Update the head of the original linked list to the element after the middle
    *l = p->prox;

    // Disconnect the first half from the second half
    p->prox = NULL;

    // Return the head of the first half of the linked list
    return u;
}



/**
 * Removes all occurrences of a given value from a linked list.
 *
 * @param l - Pointer to the head of the linked list.
 * @param x - The value to be removed.
 *
 * @return The number of occurrences of the value removed.
 */
int removeAll(LInt *l, int x) {
    int i = 0;
    LInt p;

    while (*l) {
        if ((*l)->valor == x) {
            p = (*l)->prox;
            free(*l);
            *l = p;
            ++i;
        } else {
            l = &((*l)->prox);
        }
    }

    return i;
}


/**
 * Removes duplicate elements from a linked list.
 * 
 * @param l - Pointer to the head of the linked list.
 * @return The number of removed duplicate elements.
 */
int removeDups(LInt *l) {
    int i = 0; // Counter for removed duplicate elements

    while (*l) {
        // Remove all occurrences of (*l)->valor from (*l)->prox
        i += removeAll(&((*l)->prox), (*l)->valor);

        // Move to the next node
        l = &((*l)->prox);
    }

    return i;
}


void init (LInt * l){
	while(*l && (*l)->prox)
		l = &((*l)->prox);
	if (*l) 
	{
		free(*l);
		*l = NULL;
	}

}

void concat (LInt * a, LInt b){
	while(*a)
		a=&((*a)->prox);
	*a=b;
}

int removeMaiorL (LInt *l){
   int maior;
   LInt * p,t;
   for (p = l;*p; p=&((*p)->prox))
       if((*l)->valor<(*p)->valor)
           l=p;
   maior=(*l)->valor;
   t=(*l)->prox;
   free(*l);
   *l=t;
   return maior;
}

void appendL (LInt *l, int x){
    while(*l)
        l=&((*l)->prox);
    *l=(LInt)malloc(sizeof(struct lligada));
    (*l)->valor=x;
    (*l)->prox=0;
}

LInt cloneL (LInt l)
{
	LInt r,* e=&r;
	while(l)
	{
		*e=malloc(sizeof(struct lligada));
		(*e)->valor=l->valor;
		l=l->prox;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

LInt cloneRev (LInt l){
    LInt r=0,v=0;
    while(l){
        r=(LInt) malloc (sizeof (struct lligada));
        r->valor=l->valor;
        r->prox=v;
        v=r;
        l=l->prox;
    }
    return r;
}

int maximo (LInt l){
    int max;
    for(max=l->valor;l;l=l->prox)
    if(max<l->valor) max=l->valor;
    return max;
}

int take (int n, LInt *l){
    LInt p;
    int i;
    for(i=0;*l && n>i;++i)
    l=&((*l)->prox);
    while(*l)
    {
        p=(*l)->prox;
        free(*l);
        *l=p;
    }
    return i;
}

int drop (int n, LInt *l){
    LInt p;
    int i;
    for(i=0;*l && n>i;++i)
    {
        p=(*l)->prox;
        free(*l);
        *l=p;
    }
    return i;
}

LInt NForward (LInt l, int N){
    for(;l && N>0;--N)
        l=l->prox;
    return l;
}

int listToArray (LInt l, int v[], int N){
    int i;
    for(i=0;l && i<N;++i,l=l->prox)
        v[i]=l->valor;
    return i;
}

LInt arrayToList1 (int v[], int N){
	int i=0;
	LInt r,* e=&r;
	while(i<N)
	{
		*e=malloc(sizeof(struct lligada));
		(*e)->valor=v[i];
		++i;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

LInt arrayToList2 (int u[], int N){
    LInt r=0,v=0;
    while(N>0){
        r=(LInt) malloc (sizeof (struct lligada));
        r->valor=u[N-1];
        r->prox=v;
        v=r;
        N--;
    }
    return r;
}

LInt somasAcL (LInt l) 	{
    int i=0;
    LInt r,* e=&r;
	while(l)
	{
		*e=malloc(sizeof(struct lligada));
		i+=l->valor;
		(*e)->valor=i;
		l=l->prox;
		e=&((*e)->prox);
	}
	*e=NULL;
	return r;
}

void remreps (LInt l){
    LInt p,j;
    while(l)
    {   p=l->prox;
        while(p && l->valor==p->valor)
        {
            j=p->prox;
            free(p);
            p=j;
        }
        l->prox=p;
        l=l->prox;
    }
}

LInt rotateL (LInt l){
    LInt * p=&l,m=0;
    while(*p)
        p=&((*p)->prox);
    *p=l;
    if(l)
    {
    m=l->prox;
    l->prox=0;
    }
    return m;
}



void main()

{

    LInt head, first, temp = 0;
    int count = 0;
    int choice = 1;
    first = 0;

    while (choice)
    {

        head  = (LInt)malloc(sizeof(struct lligada));
        printf("Enter the data item\n");
        scanf("%d", &head-> valor);
        if (first != 0)

        {

            temp->prox = head;

            temp = head;

        }

        else

        {
            first = temp = head;

        }
        fflush(stdin);
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);

    }
    temp->prox = 0;
    /*  reset temp to the beginning */
    temp = first ;//"first" to make one or more length list, "0" if want empty list
    printf("\n status of the linked list is\n");
 
    temp=cloneLL(temp);
    while (temp != 0)
	{

        printf("%d=>", temp->valor);

        count++;

        temp = temp -> prox;

    }
    printf("NULL\n");
    printf("No. of nodes in the list = %d\n", count);
}
