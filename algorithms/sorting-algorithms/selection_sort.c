#include <stdlib.h>
#include <stdio.h>


int
main(void)
{
    int arr_size, i, j;
    int *arr;

    printf("Enter array size: ");
    scanf("%d", &arr_size);

    arr = malloc(arr_size * sizeof(*arr));

    printf("\n");
    for(i = 0; i < arr_size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    /* implementing selection sort */
    for(i = 0; i < arr_size - 1; i++) {
        int min = arr[i];
        int j_min = i;
        for(j = i + 1; j < arr_size; j++) {
            if(arr[j] < min) {
                min = arr[j];
                j_min = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[j_min];
        arr[j_min] = temp;
    }

    printf("\nSorted array: ");
    for(i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}