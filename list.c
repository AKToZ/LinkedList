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
list * del(list *curr,int d){
    if (curr==NULL)
        return NULL;
    
    if(curr->data==d){
        list *p=curr->next;
        free(curr);
        return p;
    }
    curr->next=del(curr->next,d);
    
    
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

    head=del(head,2);
    print(head);
    return 0;
}
