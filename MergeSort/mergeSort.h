//
// Created by Pablo Chávez on 11/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_MERGESORT_H
#define DATASTRUCTUREANDALGORITHMS_MERGESORT_H

// Merge Helper Function
void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    // Merge function first part
    // This part initializes the left and right arrays and fill them.
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++)
    {
        rightArray[j] = array[midIndex + 1 + j];
    }

    // Second part of the merge function
    int index = leftIndex;
    int i = 0;
    int j = 0;
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }
    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        index++;
        i++;
    }
    while (j < rightArraySize)
    {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

/*
 * MergeSort
 * First: MergeSort will break arrays in half
 * Second: BASE CASE: When sub-array size is 1
 * Third: MergeSort will call merge() function to put sub-arrays together
 * --MergeSort will recursively call itself to break arrays in half--
 *
 *
*/

void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

#endif //DATASTRUCTUREANDALGORITHMS_MERGESORT_H
