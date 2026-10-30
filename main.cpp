#include <iostream>
#include "TreeTraversal/TreeTraversal.h"
#include "BasicSorts/basic_sorts.h"
#include "MergeSort/mergeSort.h"
#include "DynamicProgramming/fibonacci.h"
int main()
{
    /*
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);
    myBST->BFS();
    std::cout << "\n";
    myBST->DFSPreOrder();
    std::cout << "\n";
    myBST->DFSPostOrder();
    std::cout << "\n";
    myBST->DFSInOrder();
    */

    // int myArray[] = { 6, 4, 2, 5, 1, 3};
    // // int myArray[] = { 1, 3, 7, 8, 2, 4, 5, 6};
    // int size = sizeof(myArray) / sizeof(myArray[0]);
    // //merge
    // int leftIndex = 0;
    // int rightIndex = size - 1;
    // int midIndex = (size / 2) - 1;
    // merge(myArray, leftIndex, midIndex, rightIndex);
    // mergeSort(myArray, leftIndex, rightIndex);
    // for (auto value : myArray)
    // {
    //     std::cout << value << " ";
    // }

    fibonacci fib;
    int n = 30;
    std::cout << "\nFib of " << n << " = " << fib.fib(n) << "\n";
    std::cout << "\nFibonacci counter: " << fib.counter << "\n";

    // for (auto value : myArray)
    // {
    //     std::cout << value << " ";
    // }
    // std::cout << "\n";
    // basic_sorts bs;
    // // bs.bubbleSort(myArray, size);
    // // bs.selectionSort(myArray, size);
    // bs.insertionSort(myArray, size);
    // for (auto value : myArray)
    // {
    //     std::cout << value << " ";
    // }

}

