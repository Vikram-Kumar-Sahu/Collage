#include<stdio.h>
#include<stdlib.h> 
struct node{
    int data;
    struct node*link;

};

struct node* insertAtFirst(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    if(head == NULL) {
        // If the list is empty, initialize it with the new node
        ptr->link = ptr; // Points to itself, making it circular
        return ptr;
    }
    struct node* p = head;
    while(p->link != head) {
        p = p->link;
    }
    p->link = ptr;  // Last node points to the new node
    ptr->link = head; // New node points to the old head
    head = ptr; // Update head to the new node

    return head;
}

struct node*insertAtIndex(struct node* head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node*p=head;
    for(int i=1;i<index-1;i++){
        p=p->link;
    }
    ptr->link=p->link;
    p->link=ptr;
    return head;
}
struct node*insertAtLast(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    if(head == NULL) {
        // If the list is empty, initialize it with the new node
        ptr->link = ptr; // Points to itself, making it circular
        return ptr;
    }
    struct node* p = head;
    while(p->link != head) {
        p = p->link;
    }ptr->link=head;
    p->link=ptr;
    return head;
}
void Traversal(struct node*head){
    struct node *ptr=head;
    do{
        printf("elements is %d\n",ptr->data);
        ptr=ptr->link;
    }while(ptr!=head);
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
            newnode->link=head;
            pointer->link=newnode;
            pointer=newnode;
        }
        pointer=head;
        Traversal(head);
        // head=insertAtFirst(head,56);
        // Traversal(head);
        // head=insertAtLast(head,56);
        // Traversal(head);
        insertAtIndex(head,56,3);
        Traversal(head);
    }
}