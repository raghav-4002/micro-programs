#include <stdlib.h>
#include <stdio.h>


struct node {
    int info;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;


struct node **stack = NULL;
int top = -1;


void
inorder(struct node *root)
{
    struct node *ptr = root;

    while(ptr != NULL) {
        top++;
        stack[top] = ptr;
        ptr = ptr->left;
    }

    while(stack[top]->right == NULL && top != -1) {
        printf("%d ", stack[top]->info);
        top--;
    }

    printf("%d ", stack[top]->info);
    root = stack[top]->right;
    top--;

    if(top == -1) return;
    
    inorder(root);
}


int
main(void)
{
    int total_nodes;
    int element;
    struct node *new = NULL;
    struct node *parent = NULL;
    struct node *ptr = NULL;

    stack = malloc(99 * sizeof(*stack));

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
            parent = NULL;
            ptr = root;

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


    printf("Inorder: ");
    inorder(root);
    root = stack[top]->right;

    return 0;
}