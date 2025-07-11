//Josephus game or kth player eliminate problem
#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void insertAtend(int data)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
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
void makecircular()
{
    if(head!=NULL&&tail!=NULL)
    {
        tail->next=head;
        head->prev=tail;
    }
}

int solveJosephus( int k) {
    struct Node *current = head;
    int count;

    while (current->next != current) {
        count = 1;
        while (count < k) {
            current = current->next;
            count++;
        }

        printf("Player %d is eliminated\n", current->data);

        // Remove current
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // Update head if current is head
        if (current == head)
            head = current->next;

        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    printf("Player %d is the winner!\n", current->data);
    int winner = current->data;
    free(current);
    return winner;
}


int main() {
    int n, k;
    //struct Node* head = NULL;
    //struct Node* tail = NULL;

    printf("Enter number of players: ");
    scanf("%d", &n);

    printf("Enter value of k (eliminate every k-th player): ");
    scanf("%d", &k);

    // Insert players
    for (int i = 1; i <= n; i++) {
        insertAtend(i);
    }

    // Make circular (single pointer version)
    makecircular();

    // Solve the game
    solveJosephus(k);

    return 0;
}


