#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int data;
    struct node* link;
};



struct node* createNewNode(int data){
    struct node* newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;

    return newNode;
}


struct node* insertAtEnd(struct node* start, int data){
    if(start==NULL){
    start=createNewNode(data);
    return start;
    }
    struct node* temp=start;
    while(temp->link!=NULL){
    temp=temp->link;
    }
    temp->link=createNewNode(data);
    return start;
}

struct node*  insertAtFront(struct node* start, int data){
    struct node* temp=start;
    start=createNewNode(data);
    start->link=temp;
    return start;
}

void printLL(struct node* start){
    struct node* temp=start;
    while(temp->link!=NULL){
            printf("%d->",temp->data);
            temp=temp->link;
    }
    printf("%d",temp->data);
    return;
}



// function to count the number of occurences in a linked list.

int countOccurences(struct node * start, int target){
    int count=0;
    struct node* temp=start;

    while(temp!=NULL){
        if(temp->data==target) count++;
        temp=temp->link;
    }

    return count;
}

//function to find the smallest and the largest in a linked list.

void smallestAndLargestElements(struct node* start){
    if(start==NULL) {
        printf("The linked list is empty.");
    }

    struct node* temp=start;

    int max=INT_MIN;
    int min=INT_MAX;
     while(temp!=NULL){
       max=(max>temp->data)?max:temp->data;
       min=(min<temp->data)?min:temp->data;
       temp=temp->link;
    }

    printf("The smallest element is %d and the largest element is %d",min,max);

}

// Function to check if two linked lists are identical

int isIdentical(struct node * start1, struct node * start2){
    struct node* temp1=start1;
    struct node* temp2=start2;
    int flag=1;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data!=temp2->data) flag=0;
        temp1=temp1->link;
        temp2=temp2->link;
    }

    if(temp1!=NULL||temp2!=NULL) flag=0;

    return flag;

}

//Function to create a copy of a single linked list.

struct node* createCopy(struct node* start){
    if(start==NULL) return NULL;

    struct node* temp1=start;
    struct node* temp2=NULL;
    struct node* newStart=NULL;
    
    while(temp1!=NULL){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=temp1->data;
        newNode->link=NULL;

        if(newStart==NULL){
            newStart=newNode;
            temp2=newStart;
        }
        else{
            temp2->link=newNode;
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
        
    return newStart;

}


// Function to create a copy of a linked list which is the reverse of the original linked list.

struct node * createReverseCopy(struct node* start){
    struct node* newStart=NULL;
    struct node* temp=start;
    while(temp!=NULL){
        struct node* newNode=(struct node*) malloc(sizeof(struct node));
        newNode->data=temp->data;

        if(newStart==NULL){
            newStart=newNode;
            newStart->link=NULL;
        }

        else{
                newNode->link=newStart;
                newStart=newNode;

        }

       temp=temp->link;
    
    }
 return newStart;
}

//Function to swap the first and the last node of a linked list by exchanging the data part.

struct node* swapFirstnLast1(struct node* start){
    if(start==NULL||start->link==NULL) exit(1);

    struct node* temp=start;
    while(temp->link!=NULL){
        temp=temp->link;
    }

    int tempdata=temp->data;
    temp->data=start->data;
    start->data=tempdata;

    return start;
}

//Function to swap the first and the last node of a linked list by modifying the links.

struct node* swapFirstnLast1(struct node* start){
    if(start==NULL||start->link==NULL) exit(1);

    struct node* temp=start;
    struct node* prev=NULL;
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }

    prev->link=start;
    temp->link=start->link;
    start->link=temp;
    prev->link->link=NULL;

    return start;
}

// Function to move the largest element of a single linked list to the end .

struct node* shiftLargestElement(struct node* start){

        if(start==NULL|| start->link==NULL){

            printf("There no sufficient elements in the linked list to perform the operation");

            exit(1);
        }

        struct node* temp=start;
        struct node* Largest=start;
        struct node* prev=NULL;
        int largest=start->data;

        while(temp->link!=NULL){
            
            if(temp->link->data>largest){
                prev=temp;
                temp=temp->link;
                largest=temp->data;
                Largest=temp;
            }
            else{
            temp=temp->link;
            }
        
        }
        if(Largest==temp) return start;
        if(prev==NULL) {
            temp->link=start;
            start=start->link;
            temp->link->link=NULL;
        }
        else{
            prev->link=Largest->link;
            temp->link=Largest;
            Largest->link=NULL;
        }

       return start;

}

void main(){
    
    struct node* start=createNewNode(5);
    start=insertAtFront(start,6);
    start=insertAtFront(start,7);
    start=insertAtEnd(start,8);
    start=insertAtEnd(start,9);
    printLL(start);
    smallestAndLargestElements(start);


}