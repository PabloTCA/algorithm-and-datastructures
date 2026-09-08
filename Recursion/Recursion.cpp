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
        /**
         *    Binary Search Tree
         *    Insert method but recursive
         *    @params currentNode, value
         *    @return currentNode
         *    @params value
         *    @return void
         *
         */
        Node* rInsert(Node* currentNode, int value)
        {
            if (currentNode == nullptr)
            {
                return new Node(value);
            }
            if (value < currentNode -> value)
            {
                currentNode->left = rInsert(currentNode->left, value);
            }
            else if (value > currentNode -> value)
            {
                currentNode->right = rInsert(currentNode->right, value);
            }
            return currentNode;
        }
        void rInsert(int value)
        {
            if (root == nullptr) root = new Node(value);
            rInsert(root, value);
        }
        Node* deleteNode(Node* currentNode, int value)
        {
            if (currentNode == nullptr) return nullptr;
            if (value < currentNode -> value)
            {
                currentNode->left = deleteNode(currentNode->left, value);
            }
            else if (value > currentNode->value)
            {
                currentNode->right = deleteNode(currentNode->right, value);
            }
            else
            {
                //4 Cases
                /** The first 3 cases are here
                 * 1st Delete a node that is a leaf node
                 * 2nd Delete a node that has a node on the right and is open on the left
                 * 3rd Delete a node that has a node on the left and is open on the right
                 */
                // 1st Case
                if (currentNode->left == nullptr && currentNode->right == nullptr)
                {
                    delete currentNode;
                    return nullptr;
                }
                // 2nd Case
                else if (currentNode->left == nullptr)
                {
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                }
                // 3rd Case
                else if (currentNode->right == nullptr)
                {
                    Node* temp = currentNode->left;
                    delete(currentNode);
                    return temp;
                }
                // 4th Case when we delete a node that has a child on the left and the right
                else
                {
                    int subTreeMin = minValue(currentNode->right);
                    currentNode->value = subTreeMin;
                    currentNode->right = deleteNode(currentNode->right, subTreeMin);
                }

            }
            return currentNode;
        }
        void deleteNode(int value)
        {
            root = deleteNode(root, value);
        }

        /**
         * ------------Helper function that finds a minimum value----------------
         *  How to write a function that finds the minimum value?
         *  Well since we are in binary search trees we can simply travel all the way to the left
         *  and eventually we will find the minimum value that it will be one before nullptr.
         *  function name: minValue
         *  @params: Node* currentNode
         *  @return: int currentNode->value
         */
        int minValue(Node* currentNode)
        {
            while (currentNode->left != nullptr)
            {
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }

    };
}


int main()
{
    std::cout << factorial(5) << std::endl;

    rBST::BinarySearchTree* myBST = new rBST::BinarySearchTree();
    myBST->rInsert(47);
    myBST->rInsert(21);
    myBST->rInsert(76);
    myBST->rInsert(18);
    myBST->rInsert(27);
    myBST->rInsert(52);
    myBST->rInsert(82);
    std::cout << "Contains 27:\n";
    std::cout << myBST->rContains(27) << "\n";
    std::cout << "Min Value: " <<myBST->minValue(myBST->root) << "\n";

    std::cout << "Contains 17:\n";
    std::cout << myBST->rContains(17) << std::endl;

    std::cout << "Min Value root right: " <<myBST->minValue(myBST->root->right) << "\n";
    myBST->deleteNode(18);
    std::cout << "Min Value root: " <<myBST->minValue(myBST->root) << "\n";

    return 0;
}