//
// Created by Pablo Chávez on 13/09/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_BASIC_SORTS_H
#define DATASTRUCTUREANDALGORITHMS_BASIC_SORTS_H


class basic_sorts
{
public:
    void bubbleSort(int arr[], int size)
    {
        for (int i = size - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void selectionSort(int array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[minIndex])
                {
                    minIndex = j;
                }
            }
            if (i != minIndex)
            {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }
};


#endif //DATASTRUCTUREANDALGORITHMS_BASIC_SORTS_H
