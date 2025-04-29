#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void Display(struct node*ptr){
    while(ptr!=NULL){
        printf("%d->\n",ptr->data);
        ptr=ptr->link;
    }
     printf("\n");
}

struct node*insertAtFirst(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->link=head;
    ptr->data=data;
    return ptr;
}

struct node*insertAtIndex(struct node* head,int data,int index){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=1;
    while(i < index - 1 && p != NULL) {
        p=p->link;
        i++;
    }
    if(p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    ptr->data=data;
    ptr->link=p->link;
    p->link=ptr;
    return head;

}

struct node*insertAtEnd(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    while(p->link!=NULL){
        p=p->link;
    }ptr->data=data;
    p->link=ptr;
    ptr->link=NULL;
    return head;
}

struct node*deleteFirst(struct node *head){
     if(head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    struct node*ptr=head;
    head=ptr->link;
    free(ptr);
    return head;
}

struct node* deleteAtIndex(struct node*head,int index){
    struct node*p=head;
    struct node*q=p->link;
    for(int i=1;i<index-1;i++)
    {
        p=p->link;
        q=q->link;
        /* data */
    }
    p->link=q->link;
    free(q);
    return head;
}

struct node*deleteLast(struct node*head){
    struct node *p=head;
    struct node *q=p->link;
    while(q->link!=NULL){
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}
void main(){
    int size;
    printf("enter the size of the list:");
    scanf("%d",&size);
    if (size <= 0) {
        printf("The list size must be greater than 0.\n");
        return;
    }
    struct node *head=(struct node*)malloc(sizeof(struct node));
    printf("enter list items:\n");
    scanf("%d",&(head->data));
    head->link=NULL;
    int i;
    struct node*pointer=head;

    if(size>1){
        for ( i = 1; i < size; i++)
        {
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&(newnode->data));
            newnode->link=NULL;
            pointer->link=newnode;
            pointer=newnode;
        }
        
    }
    pointer=head;
    Display(head);
    // head=insertAtFirst(head,56);
    // Display(head);
    // head=insertAtIndex(head,66,3);
    // Display(head);
    // head=insertAtEnd(head,77);
    // Display(head);
    // head=deleteFirst(head);
    // Display(head);
    // head=deleteAtIndex(head,3);
    // Display(head);
    head=deleteLast(head);
    Display(head);
}
