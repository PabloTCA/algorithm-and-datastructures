//
// Created by Pablo Chávez on 25/08/26.
//
#include <iostream>
#include <vector>

class Heap
{
private:
    std::vector<int> heap;

    //Helper functions
    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }
public:
    void printHeap()
    {
        std::cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            std::cout << heap[i];
            if (i < heap.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;
        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);

        }
    }

    int remove()
    {
        if (heap.empty()) return INT_MIN;

        int maxValue = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        } else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return maxValue;
    }
    //It rearranges the heap after removing the root element
    void sinkDown(int index)
    {
        int maxIndex = index;
        while (true)
        {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);
            if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex])
            {
                maxIndex = leftIndex;
            }
            if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex])
            {
                maxIndex = rightIndex;
            }
            if (maxIndex != index)
            {
                swap(index, maxIndex);
                index = maxIndex;
            } else
            {
                return;
            }
        }
    }
};
class MinHeap
{
private:
    std::vector<int> heap;
    int leftChild(int index)
    {
        return 2 * index + 1;
    }
    int rightChild(int index)
    {
        return 2 * index + 2;
    }
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }
public:
    void printHeap()
    {
        std::cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            std::cout << heap[i];
            if (i < heap.size())
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;
        while (current > 0 && heap[current] < heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }
    int remove()
    {
        if (heap.size() == 0) return INT_MIN;
        int minValue = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        } else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return minValue;
    }
    void sinkDown(int index)
    {
        int minIndex = index;
        while (true)
        {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);
            if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex])
            {
                minIndex = leftIndex;
            }
            if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex])
            {
                minIndex = rightIndex;
            }
            if (minIndex != index)
            {
                swap(index, minIndex);
                index = minIndex;
            }
            else
            {
                return;
            }
        }
    }
};


int main()
{
    MinHeap* min_heap = new MinHeap();
    min_heap->insert(99);
    min_heap->insert(80);
    min_heap->insert(60);
    min_heap->insert(50);
    min_heap->insert(25);
    min_heap->insert(10);
    min_heap->insert(2);
    min_heap->insert(1);

    min_heap->printHeap();


    // Heap* myHeap = new Heap();
    // myHeap->insert(99);
    // myHeap->insert(72);
    // myHeap->insert(61);
    // myHeap->insert(58);
    //
    // myHeap->printHeap();
    //
    // myHeap->insert(100);
    // myHeap->printHeap();
    //
    // myHeap->insert(75);
    // myHeap->printHeap();
    //
    // myHeap->remove();
    // myHeap->printHeap();

}