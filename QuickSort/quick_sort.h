//
// Created by Pablo Chávez on 27/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_QUICK_SORT_H
#define DATASTRUCTUREANDALGORITHMS_QUICK_SORT_H


class quick_sort
{
    void swap(int array[], int firstIndex, int secondIndex)
    {
        int temp = array[firstIndex];
        array[firstIndex] = array[secondIndex];
        array[secondIndex] = temp;
    }

    int pivot(int array[], int pivotIndex, int endIndex)
    {
        int swapIndex = pivotIndex;
        for (int i = pivotIndex + 1; i <= endIndex; i++)
        {
            if (array[i] < array[pivotIndex])
            {
                swapIndex++;
                swap(array, swapIndex, i);
            }
        }
        swap(array, pivotIndex, swapIndex);
        return swapIndex;
    }
    void quickSort(int array[], int leftIndex, int rightIndex)
    {
        if (leftIndex >= rightIndex) return;
        int pivotIndex = pivot(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, rightIndex);
    }
};


#endif //DATASTRUCTUREANDALGORITHMS_QUICK_SORT_H
