#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    int priority;
    struct node *next;
};

struct node *front = NULL;


int
main(void)
{
    int queue_size, i;
    struct node *new = NULL;
    struct node *ptr = NULL, *temp = NULL;

    printf("Enter queue size: ");
    scanf("%d", &queue_size);

    for(i = 0; i < queue_size; i++) {
        new = malloc(sizeof(*new));

        printf("Enter element of queue: ");
        scanf("%d", &new->info);
        printf("Enter its priority: ");
        scanf("%d", &new->priority);
        new->next = NULL;

        if(front == NULL) {
            front = new;
        } else {
            ptr = front;
            temp = NULL;

            while(ptr != NULL && ptr->priority < new->priority) {
                temp = ptr;
                ptr = ptr->next;
            }

            if(NULL == ptr) {
                temp->next = new;
            } else if (NULL == temp) {
                new->next = ptr;
                front = new;
            } else {
                new->next = temp->next;
                temp->next = new;
            }
        }
    }

    printf("\nThe entered elements of queue are:\n");
    while(front != NULL) {
        printf("Element: %d; Priority: %d\n", front->info, front->priority);
        front = front->next;
    }
    
    printf("\n");

    return 0;
}