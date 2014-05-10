#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"


void
print_arr (int *arr, int arrlen)
{
    printf("%d", arr[0]);
    for (int i = 1; i < arrlen; i++)
        printf(", %d", arr[i]);
    printf("\n");
}

void
merge (int *subarr1, int subarr1_len, int *subarr2, int subarr2_len, int *arr)
{
    for (int i = 0, i1 = 0, i2 = 0; i1 < subarr1_len || i2 < subarr2_len; i++) {
        if (i1 < subarr1_len && i2 < subarr2_len)
            arr[i] = 
                (subarr1[i1] <= subarr2[i2]) ? subarr1[i1++] : subarr2[i2++];
        else if (i1 < subarr1_len)
            arr[i] = subarr1[i1++];
        else if (i2 < subarr2_len)
            arr[i] = subarr2[i2++];
    }
}

int *
merge_sort (int *arr, int arrlen)
{
    if (arrlen <= 1)
        return arr;

    int middle = arrlen / 2;
    int *left = arr;
    int *right = arr + middle;

    left = merge_sort(left, middle);
    right = merge_sort(right, arrlen - middle);

    /* copy subarrays into local arrays for merge */
    int l[middle];
    int r[arrlen - middle];
    for (int i = 0; i < middle; i++, left++)
        l[i] = *left;
    for (int i = 0; i < arrlen - middle; i++, right++)
        r[i] = *right;

    merge(l, middle, r, arrlen - middle, arr);
    return arr;
}
