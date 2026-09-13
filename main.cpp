#include <iostream>
#include "TreeTraversal/TreeTraversal.h"
#include "BasicSorts/basic_sorts.h"
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

    int myArray[] = { 6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    for (auto value : myArray)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
    basic_sorts bs;
    // bs.bubbleSort(myArray, size);
    bs.selectionSort(myArray, size);
    for (auto value : myArray)
    {
        std::cout << value << " ";
    }
}

