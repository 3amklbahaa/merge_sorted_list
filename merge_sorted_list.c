#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* Merge_Sorted_List(node* h1, node* h2){
    node* h = (node*)malloc(sizeof(node));
    if(h==NULL){
        return NULL;
    }
    node* c1 = h1, *c2 = h2;
    node* c = h ,*new = NULL;
    while(c1!=NULL&&c2!=NULL){
        new = (node *)malloc(sizeof(node));
        if(new==NULL){
            free(h);
            return NULL;
        }
        new->next=NULL;
        if(c1->data<=c2->data){
            new->data=c1->data;
            c1=c1->next;
        }
        else{
            new->data=c2->data;
            c2=c2->next;
        }
        c->next=new;
        c=new;
    }
    node* remaining;
    if(c1==NULL){
        remaining=c2;
    }
    else{
        remaining=c1;
    }
    while(remaining!=NULL){
        new = (node*)malloc(sizeof(node));
        if(new==NULL){
            free(h);
            return NULL;
        }
        new->next=NULL;
        new->data = remaining->data;
        remaining = remaining->next;
        c->next=new;
        c=new;
    }
    node* head = h->next;
    free(h);
    return head;
}
