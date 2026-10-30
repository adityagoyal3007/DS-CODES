#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int regNo;
    char name[50];
    struct Node *next;
}Node;
struct Node* createHead() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}
int length(struct Node *head)
{
    struct Node *temp;
    int count = 0;

    temp = head->next;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
Node *insertbypos(struct Node *head){
    int i = 1,pos,k;   //position to insert the student
    struct Node *curr = head;       //current pointer to traverse the list
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));  //new node to be inserted

    printf("Enter Registration Number: ");    
    scanf("%d", &newnode->regNo);  
    printf("Enter Student Name: ");
    scanf("%49s", newnode->name);
    printf("\nEnter position to insert : ");
    scanf("%d",&pos);
    k = length(head);
    if(pos < 1 || pos > k+1){  //if position is greater than length of the list + 1, then data cant be inserted
        printf("\nData cant be inserted");
        free(newnode);
    }
    else{ 
        while(curr!=NULL && i<pos){    //traverse the list until the position is reached
            i++;
            curr = curr->next;          //move to the next node
        }
        newnode->next = curr->next;  //link the new node to the next node of the current node
        curr->next = newnode;  //link the current node to the new node
        printf("\n Student inserted"); //print the message that the student is inserted
    }
    return head;
}


void display(struct Node *head)  
{
    struct Node *curr;

    if (head->next == NULL) //check if the list is empty
    {
        printf("List is empty\n");
    } 
    else
    {
        curr = head->next;          //set the current pointer to the first node of the list

        while (curr != NULL)  //    loop until the current pointer is NULL
        {   printf("\n");
            printf("Registration Number: %d\n", curr->regNo);
            printf("Student Name: %s\n", curr->name);

            curr = curr->next;
        }
    }
}

Node* deletebyposition(struct Node *head){      
    int pos; //position to delete the student
    struct Node *previous = head;         //previous pointer to traverse the list
    struct Node *current = head->next;    //current pointer to traverse the list
    int ctr = 1;    //counter to keep track of the position
    struct Node *temp = NULL;   //temporary pointer to store the node to be deleted
    printf("\nEnter student  position to be deleted: ");        //ask the user to enter the position of the student to be deleted
    scanf("%d",&pos);
    int u = length(head);       //get the length of the list
    if(pos < 1 || u < pos){     //if the position is greater than the length of the list, then data cant be deleted
        printf("\n Data cant be deleted ");            
    }
    else{
        while(ctr < pos && current!=NULL){  //traverse the list until the position is reached
            ctr++;  //increment the counter
            previous = current;  //move the previous pointer to the current pointer
            current = current->next;  //move the current pointer to the next node
        }
        temp = current ;  //store the current pointer in the temporary pointer
        previous->next = current->next;  // link the previous node to the next node of the current node
        current->next = NULL;   //  unlink the current node from the list
        free(temp);   //    free the memory allocated to the current node
        printf("\nStudent Deleted"); 
    }
    return head;
}

Node *sort(struct Node *head){
    struct Node *previous;
    struct Node *current;
    struct Node *temp;
    int len = length(head);
    int i,j;
    for(i=0;i<len-1;i++){
        previous = head;
        current = head->next;
        for(j=0;j<len-i-1;j++){
            temp = current->next;
            if(current->regNo > temp->regNo){
                previous->next = temp;
                current->next = temp->next;
                temp->next=current;
                previous = temp;
            }
            else{
                previous = current;
                current = current->next;
            }
        }
    }
    return head;
}

Node* reverse(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head->next; 
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    printf("List reversed successfully!\n");
    return head;
}

int main()
{
    int choice;
    struct Node *head = createHead();
    do
    {
        printf("\n1.Add Student\n");
        printf("2. Display Students\n");
        printf("3. Number of students present\n");
        printf("4. Delete a student\n");
        printf("5. Sort the list\n");
        printf("6. Reverse\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = insertbypos(head);
                break;

            case 2:
                display(head);
                break;
            case 3:
                printf("\n the number of participants are %d ",length(head));
                break;
            case 4:
                deletebyposition(head);
                printf("\nStudent Deleted.\n");
                break;
            case 5:
                sort(head);
                break;
            case 6:
                reverse(head);
                break;
            case 7:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice !=7);

    return 0;
}