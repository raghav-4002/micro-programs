/* Josephus problem implementation */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int index;
    struct node *link;
};

struct node *start = NULL;
struct node *new = NULL;

int
main(void)
{
    int size;
    int i;

    printf("Enter size: ");
    scanf("%d", &size);

    /* creating a circular list of size 'size' */
    for(i = 1; i <= size; i++) {
        if(start == NULL) {
            start = malloc(sizeof *start);
            new = start;
        }

        else {
            new->link = malloc(sizeof *new);
            new = new->link;
            new->link = start;
        }

        new->index = i;
    }
    
    /* josephus problem implementation */
    while(1) {
        if(start->link == start)
            break;
        
        new = start->link;
        printf("%d eliminated %d\n", start->index, start->link->index);
        start->link = start->link->link;
        start = start->link;
        free(new);
    }

    printf("\n%d wins! (I guess)\n", start->index);
}