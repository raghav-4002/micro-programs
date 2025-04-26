#include <stdio.h>
#include <stdlib.h>


struct {
    int left;
    int right;
} *stack;

int top = -1;


void
quicksort(int *arr)
{
    if(top == -1) return;

    int left = stack[top].left, right = stack[top].right;
    top--;

    int beg = left, end = right;
    int pivot = left;

    int temp;

    while(1) {
        while(arr[right] >= arr[pivot] && right > left)
            right--;
        if(right == left) break;

        temp = arr[pivot];
        arr[pivot] = arr[right];
        arr[right] = temp;
        pivot = right;

        while(arr[left] <= arr[pivot] && right > left)
            left++;
        if(right == left) break;

        temp = arr[pivot];
        arr[pivot] = arr[left];
        arr[left] = temp;
        pivot = left;
    }

    if(pivot - beg > 1) {
        top++;
        stack[top].left = beg, stack[top].right = pivot - 1;
    }
    if(end - pivot > 1) {
        top++;
        stack[top].left = pivot + 1, stack[top].right = end;
    }

    quicksort(arr);
}


int
main(void)
{
    stack = malloc(99 * sizeof(*stack));

    int *arr;
    int arr_size, i;

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    arr = malloc(sizeof(*arr));

    for(i = 0; i < arr_size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    } 

    top++;
    stack[top].left = 0, stack[top].right = arr_size - 1;

    quicksort(arr);

    printf("Sorted array: ");
    for(i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}