//scavenger hunt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char clue[100];//
    struct Node *next;
    struct Node *prev;
};
//head pointer null 
struct Node* head=NULL;
struct Node* tail=NULL;
struct Node* createNode(char clue[]){//believer 
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->clue, clue);
    newNode->next=NULL;
    return newNode;
}
void addClue(char song[]){
    struct Node* newNode=createNode(song);
    newNode->prev=tail;
    newNode->next=NULL;
    if(tail==NULL)
    {
        head=newNode;
    }
    else
    {
        tail->next=newNode;
    }
    tail=newNode;
}
void display(){
    if(head==NULL)
    {
        printf("\n No songs to play...");return;}
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%s ->",temp->clue);
        temp=temp->next;
    }printf("Found");
}

int main()

{
    int choice;char hint[100];
    while(1){printf("Choice 1: Add a clue\nChoice 2: Display clue\nChoice 3: Exit\nEnter your choice\n");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("Enter the hint\n");
            fgets(hint, sizeof(hint), stdin);
            hint[strcspn(hint, "\n")] = 0; 
            addClue(hint);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Exit the scavenger hunt");
            exit(0);
        default:
            printf("Enter valid choice");
    }}return 0;
}



















    
    
    
    
    
    
    
