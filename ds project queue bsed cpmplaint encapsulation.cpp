#include <stdio.h>
#include <string.h>

#define MAX 10

struct Complaint {
    int id;
    char name[30];
    char issue[50];
    int priority;
};

struct Complaint queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue() {
    if (isFull()) {
        printf("\nQueue is full! Cannot add complaint.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

    printf("\nEnter Complaint ID: ");
    scanf("%d", &queue[rear].id);

    printf("Enter Name: ");
    scanf("%s", queue[rear].name);

    printf("Enter Issue: ");
    scanf("%s", queue[rear].issue);

    printf("Enter Priority (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &queue[rear].priority);

    printf("\nComplaint registered successfully!\n");
}

void dequeue() {
    if (isEmpty()) {
        printf("\nNo complaints to resolve.\n");
        return;
    }

    printf("\nResolved Complaint ID: %d\n", queue[front].id);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nNo complaints in queue.\n");
        return;
    }

    printf("\n--- Complaint List ---\n");
    for (int i = front; i <= rear; i++) {
        printf("\nID: %d", queue[i].id);
        printf("\nName: %s", queue[i].name);
        printf("\nIssue: %s", queue[i].issue);
        printf("\nPriority: %d", queue[i].priority);
        printf("\n--------------------");
    }
}

void escalate() {
    int id, newPriority, found = 0;

    printf("\nEnter Complaint ID to escalate: ");
    scanf("%d", &id);

    for (int i = front; i <= rear; i++) {
        if (queue[i].id == id) {
            printf("Enter New Priority (1-High): ");
            scanf("%d", &newPriority);
            queue[i].priority = newPriority;
            found = 1;
            printf("\nComplaint escalated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nComplaint ID not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n\n=== Complaint Escalation System ===");
        printf("\n1. Register Complaint");
        printf("\n2. Resolve Complaint");
        printf("\n3. Display Complaints");
        printf("\n4. Escalate Complaint");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: escalate(); break;
            case 5: printf("\nThank you!\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
