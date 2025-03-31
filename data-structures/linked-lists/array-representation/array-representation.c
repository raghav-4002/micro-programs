#include <stdio.h>
#include <stdlib.h>


#define NONE -1


int
main(void)
{
    int new = NONE, start = NONE, ptr = NONE;
    int *info = NULL, *link = NULL;
    int list_size, i;

    printf("Enter list size: ");
    scanf("%d", &list_size);

    for(i = 1; i <= list_size; i++) {
        new++;

        if(start == NONE) {
            start = new, ptr = new;
        } else {
            link[ptr] = new;
            ptr = link[ptr];
        }

        info = realloc(info, sizeof(new) * (new + 1));
        printf("Enter item %d: ", i);
        scanf("%d", &info[ptr]);

        link = realloc(link, sizeof(new) * (new + 1));
        link[ptr] = NONE;
    }

    printf("\nList items: ");
    while(start != NONE) {
        printf("%d, ", info[start]);
        start = link[start];
    }

    return 0;
}