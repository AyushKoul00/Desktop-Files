#include <stdio.h>
#include <stdlib.h>

//DLL
typedef struct node
{
    int info;
    struct node *next, *prev;
} Node;

void insert(Node **head, Node **tail, int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->prev = *tail;
    p->info = k;
    if (!*head)
        *head = p;
    else
        (*tail)->next = p;
    *tail = p;
}

void orderInsert(Node **head, int k)
{
   if(!*head)
   {
       Node *p = (Node*) malloc(sizeof(Node));
       p->next = p->prev = NULL;
       p->info = k;
       *head = p;
   }
   else if((*head)->info > k)
   {
       Node *p = (Node*) malloc(sizeof(Node));
       p->next = *head;
       p->prev = (*head)->prev;
       (*head)->prev = p;
       p->info = k;
       *head = p;
   }
   else
       orderInsert(&((*head)->next), k);
}

void display(Node *n)
{
    while(n){
        printf("%d ", n->info);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL, *tail = NULL;
    // insert(&head, &tail, 7);
    // display(head);
    // insert(&head, &tail, 4);
    // display(head);
    // insert(&head, &tail, 5);
    // display(head);
    // insert(&head, &tail, 4);
    // display(head);
    // insert(&head, &tail, 5);
    // display(head);

    orderInsert(&head, 8);
    display(head);
    orderInsert(&head, 2);
    display(head);
    orderInsert(&head, 20);
    display(head);
    orderInsert(&head, 10);
    display(head);
    orderInsert(&head, 6);
    display(head);
    orderInsert(&head, 1);
    display(head);
    orderInsert(&head, 100);
    display(head);
}