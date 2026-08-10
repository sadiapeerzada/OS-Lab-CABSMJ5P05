#include <stdio.h>

#define MAX 20

char queue[MAX][20];
int front = -1, rear = -1;

void enqueue(char name[]) {
    if (rear == MAX - 1) {
        printf("Ready queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    // simple string copy
    int i = 0;
    while (name[i] != '\0') {
        queue[rear][i] = name[i];
        i++;
    }
    queue[rear][i] = '\0';
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Ready queue is empty!\n");
        return;
    }
    printf("Executing process: %s\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Ready queue is empty!\n");
        return;
    }
    printf("Current Ready Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%s ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    char temp[20];
    for (i = 0; i < n; i++) {
        printf("Enter name of process %d: ", i + 1);
        scanf("%s", temp);
        enqueue(temp);
    }

    printf("\n");
    display();

    printf("\nSimulating execution (FCFS order):\n");
    for (i = 0; i < n; i++) {
        dequeue();
    }

    return 0;
}
