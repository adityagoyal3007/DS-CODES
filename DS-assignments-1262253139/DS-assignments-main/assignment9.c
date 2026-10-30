#include <stdio.h>
#include <string.h>

#define MAX 5          
#define TITLE_LEN 50   

typedef struct {
    int  jobId;
    char title[TITLE_LEN];
} PrintJob;

typedef struct {
    PrintJob jobs[MAX];
    int front;   
    int rear;    
    int count;   
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(CircularQueue *q) {
    return q->count == MAX;
}

int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

void enqueue(CircularQueue *q, int id, const char *title) {
    if (isFull(q)) {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;        
    q->jobs[q->rear].jobId = id;  
    strncpy(q->jobs[q->rear].title, title, TITLE_LEN - 1);
    q->jobs[q->rear].title[TITLE_LEN - 1] = '\0';
    q->count++;
    printf("Print job added successfully: Job ID %d, \"%s\"\n", id, title);
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }
    PrintJob job = q->jobs[q->front];
    q->front = (q->front + 1) % MAX;        
    q->count--;
    printf("Processed print job: Job ID %d, \"%s\"\n", job.jobId, job.title);
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("No pending print jobs. Queue is empty.\n");
        return;
    }
    printf("\nPending Print Jobs (FIFO order):\n");
    printf("%-5s %-10s %s\n", "No.", "Job ID", "Document Title");
    printf("\n");
    int i = q->front;
    for (int n = 0; n < q->count; n++) {
        printf("%-5d %-10d %s\n", n + 1, q->jobs[i].jobId, q->jobs[i].title);
        i = (i + 1) % MAX;
    }
    printf("\n");
    printf("Total pending jobs: %d / %d\n", q->count, MAX);
}

int main(void) {
    CircularQueue q;
    int choice, id;
    char title[TITLE_LEN];

    initQueue(&q);
    printf("Queue is initialized successfully.\n");

    do {
        printf("\n= PRINTER QUEUE MANAGER =\n");
        printf("1. Add a Print Job (Enqueue)\n");
        printf("2. Process a Print Job (Dequeue)\n");
        printf("3. Display All Pending Print Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                if (isFull(&q)) {
                    printf("Queue Overflow! Print queue is full.\n");
                    break;
                }
                printf("Enter Job ID: ");
                scanf("%d", &id);
                printf("Enter Document Title: ");
                scanf(" %49[^\n]", title);   /* reads a title with spaces */
                enqueue(&q, id, title);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}