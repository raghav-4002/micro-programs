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

    int item;

    printf("Enter item to search: ");
    scanf("%d", &item);

    struct node *ptr = root;
    struct node *parent = NULL;

    while(ptr != NULL && ptr->info != item) {
        parent = ptr;
        if(item < ptr->info) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }

    if(ptr == NULL) {
        printf("Item doesn't exist.\n");
        printf("Adding the item to the tree...\n");

        new = malloc(sizeof(*new));
        new->info = item;
        new->left = NULL;
        new->right = NULL;

        if(item < parent->info) {
            parent->left = new;
        } else {
            parent->right = new;
        }
    } else {
        printf("Item exists\n");
    }

    return 0;
}