#include <stdlib.h>
#include <stdio.h>


struct node {
    int info;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;


int
main(void)
{
    int total_nodes;
    int element;
    struct node *new = NULL;

    printf("Enter total nodes: ");
    scanf("%d", &total_nodes);

    for(int i = 0; i < total_nodes; i++) {
        printf("\nEnter %d element: ", i + 1);
        scanf("%d", &element);

        new = malloc(sizeof(*new));
        new->info = element;
        new->left = NULL;
        new->right = NULL;

        if(root == NULL) {
            root = new;
        } else {
            struct node *parent = NULL;
            struct node *ptr = root;

            while(ptr != NULL) {
                parent = ptr;

                if(element > ptr->info) {
                    ptr = ptr->right;
                } else {
                    ptr = ptr->left;
                }
            }

            if(parent->info > element) {
                parent->left = new;
            } else {
                parent->right = new;
            }
        }
    }

    return 0;
}