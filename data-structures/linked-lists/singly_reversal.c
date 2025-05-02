#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node *link;
};


struct node*
list_reversal(struct node *ptr)
{
    if(ptr == NULL) {
        printf("List doesn't exist\n");
        return NULL;
    }

    struct node *p = NULL, *q = ptr, *r = ptr->link;

    while(1) {
        q->link = p;
        p = q;
        q = r;

        if(q == NULL) break;

        r = r->link;
    }

    return p;
}


int
main(int argc, char *argv[])
{
    struct node *start = NULL;
    struct node *new = NULL;
    struct node *ptr = NULL;

    int list_size = atoi(argv[1]);

    for(int i = 0; i < list_size; i++) {
        new = malloc(sizeof(*new));
        new->link = NULL;
        printf("Enter node %d: ", i + 1);
        scanf("%d", &(new->info));

        if(start == NULL) {
            start = new;
            ptr = start;
        } else {
            ptr->link = new;
            ptr = ptr->link;
        }
    }

    ptr = list_reversal(start);

    printf("\nList(in reverse): ");
    while(ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }

    return 0;
}