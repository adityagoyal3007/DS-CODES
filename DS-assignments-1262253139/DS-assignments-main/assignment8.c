#include <stdio.h>
#include <string.h>
#define MAX 5

struct job { int jobID; char name[50]; };
struct job jobs[MAX];
int front = -1, rear = -1;

int isEmpty(void)
{
    return front == -1;
}

int isFull(void)
{
    return (rear + 1) % MAX == front;
}

void addJob(int id, char name[])
{
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    jobs[rear].jobID = id;
    strcpy(jobs[rear].name, name);
    printf("Job added: ID = %d, Name = %s\n", id, name);
}

void processJob(void)
{
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Processed job: ID = %d, Name = %s\n", jobs[front].jobID, jobs[front].name);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void displayJobs(void)
{
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Pending print jobs:\n");
    i = front;
    while (1) {
        printf("ID: %d  Name: %s\n", jobs[i].jobID, jobs[i].name);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main(void)
{
    int choice, id;
    char name[50];
    do {
        printf("\n1. Add Job\n2. Process Job\n3. Display Jobs\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter job name: "); scanf("%49s", name);
                printf("Enter job ID: "); scanf("%d", &id);
                addJob(id, name);
                break;
            case 2: processJob(); break;
            case 3: displayJobs(); break;
            case 4: printf("Exit.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
