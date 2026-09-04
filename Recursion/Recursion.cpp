//
// Created by Pablo Chávez on 03/09/26.
//
#include <iostream>
/**
 *  Factorial function.
 *  The purpose of this example is to demonstrate the use of recursion to calculate the factorial of a number.
 *  @param n: The number to calculate the factorial of.
 *  @return: The factorial of the number.
 */
int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n - 1);
}
namespace rBST
{
    class Node
    {
    public:
        int value;
        Node* right;
        Node* left;
        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
    };

    class BinarySearchTree
    {
    public:
        Node* root;
    public:
        BinarySearchTree()
        {
            root = nullptr;
        }
        bool insert(int value)
        {
            Node* newNode = new Node(value);
            if (root == nullptr){
                root = newNode;
                return true;
            }
            Node* temp = root;
            while (true)
            {
                if (newNode -> value == temp -> value) return false;
                if (newNode -> value < temp -> value)
                {
                    if (temp -> left == nullptr)
                    {
                        temp -> left = newNode;
                        return true;
                    }
                    temp = temp -> left;
                }
                else
                {
                    if (temp -> right == nullptr)
                    {
                        temp -> right = newNode;
                        return true;
                    }
                    temp = temp -> right;
                }
            }
        }
      /**
       *    Binary Search Tree
       *    Contains method but recursive
       *    @params currentNode, value
       *    @return bool
       */
        bool rContains(Node* currentNode, int value)
        {
            if (currentNode == nullptr) return false;
            if (currentNode -> value == value) return true;
            if (value < currentNode -> value) return rContains(currentNode->left, value);
            if (value > currentNode -> value) return rContains(currentNode->right, value);
        }
        bool rContains(int value)
        {
            return rContains(root, value);
        }

    };
}


int main()
{
    std::cout << factorial(5) << std::endl;

    rBST::BinarySearchTree* myBST = new rBST::BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);
    std::cout << "Contains 27:\n";
    std::cout << myBST->rContains(27) << "\n";

    std::cout << "Contains 17:\n";
    std::cout << myBST->rContains(17) << std::endl;

    return 0;
}