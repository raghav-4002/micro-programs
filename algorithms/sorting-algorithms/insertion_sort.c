#include <stdio.h>
#include <stdlib.h>


int
main(void)
{
    int arr_size, i, j, k;
    int *arr;

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    arr = malloc(arr_size * sizeof(*arr));

    printf("\n");
    for(i = 0; i < arr_size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    /* implementing insertion sort */
    for(i = 1; i < arr_size; i++) {
        k = i;
        for(j = i - 1; j >= 0 && arr[j] > arr[k]; j--) {
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;

            k = j;
        }
    }

    printf("\nSorted array: ");
    for(i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}