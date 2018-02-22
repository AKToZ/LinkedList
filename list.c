#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
}list;

void insert(list *head,int d){
    if(head->next)
        insert(head->next,d);
    if(!head->next){
        list *t=malloc(sizeof(list));
        t->data=d;
        t->next=NULL;
        head->next=t;
    }
}
void del(list **head,int d){
    list *p,*last=NULL;
    p=*head;
    while(p->data!=d){
        last=p;
        p=p->next;
    }
    if(last==NULL){
        *head=p->next;
        
    }
    else
        last->next=p->next;
    free(p);
}

void print(list *head){
    while(head){
        printf(" %d -> ",head->data);
        head=head->next;
    }
        
}

int main()
{   list *p,*head;
    p=malloc(sizeof(list));
    p->next=NULL;
    head=p;
    head->data=2;
    printf("Hello World");
    insert(head,3);
    insert(head,5);
    insert(head,6);

    del(&head,3);
    print(head);
    return 0;
}
