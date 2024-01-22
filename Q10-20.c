#include <stdio.h>
#include<stdlib.h>


// Function to delete all the nodes having a value n.

struct node* deleteNode(struct node * start, int target){

    struct node* t=start;
    struct node* temp=NULL;
    if(start==NULL){
        return start;
    }
    
        
    if(start->data==target){
            temp=start;
            start=start->link;
            free(temp);
    }

    
   
    while(t->link!=NULL){
        
        if(t->link->data==target){

            temp=t->link;
            t->link=temp->link;
            free(temp);
      

        }
    }

    return start;

}

// Function to print the elements of a linked list with respect to the elements of another sorted linked list.

void printElements(struct node* start1, struct node* start2){
    if(start2==NULL||start2==NULL) return;
    struct node* temp1=start1;
    struct node* temp2=start2;

    int count=1;

    while(temp2!=NULL && temp1!=NULL){

        if(count==temp1->data){
            printf("%d ",temp2->data);
            temp1=temp1->link;
        }
        temp2=temp2->link;
        count++;
    
    }

}
// Function to remove the last node and insert it to the start
struct node* shiftLastToFirst(struct node* start){

    if(start==NULL|| start->link==NULL) return start;

    struct node* temp=start;
    while(temp->link->link!=NULL){

        temp=temp->link;
    }

    temp->link->link=start;

    start=temp->link;
    temp->link=NULL;
    
    return start;
}

// Function to remove the first node and insert it to the last.

struct node* shiftFirstToLast(struct node* start){

    if(start==NULL|| start->link==NULL) return start;

    struct node* temp=start;
    while(temp->link!=NULL){

        temp=temp->link;
    }

    temp->link=start;
    start=start->link;
    temp->link->link=NULL;

    return start;
}

// Function to move a node n positions forward in a single linked list.
void moveNode(struct node* node, int n){
    if(node==NULL||node->next==NULL){
            printf("Cannot move the node to %d positions",n);
            exit(1);
        }
    struct node* temp=node;
    while(n){
        if(temp->link==NULL){
            printf("Cannot move the node to %d positions",n);
            exit(1);
        }
        temp=temp->link;
        n--;
        
    }
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=node->data;
    newNode->link=NULL;
    newNode->link=temp->link;
    temp->link=newNode;

        struct node* ptr=node->link;
    node->data=node->link->data;
    node->link=node->link->link;

    free(ptr);

}


// Function to delete a node, the only given information is a pointer to the node that is to be deleted.

void deleteNode(struct node* node){
    if(node==NULL||node->link==NULL){
    printf("Cannot perform this operation.");
    }
    struct node* temp=node->link;
    node->data=node->link->data;
    node->link=node->link->link;

    free(temp);

}


