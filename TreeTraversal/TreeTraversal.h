//
// Created by Pablo Chávez on 12/09/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_TREETRAVERSAL_H
#define DATASTRUCTUREANDALGORITHMS_TREETRAVERSAL_H



#include <iostream>
#include <queue>

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

    BinarySearchTree()
    {
        root = nullptr;
    }

    bool insert(int value)
    {
        Node* newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        Node* temp = root;

        while (true)
        {
            if (newNode->value == temp->value) return false;

            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }

                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }

                temp = temp->right;
            }
        }
    }

    /**
     * Tree Traversal: Breadth-First Search (BFS)
     * Function to perform Breadth-First Search (BFS) traversal of a binary tree.
     */
    void BFS()
    {
        if (root == nullptr) return;

        std::queue<Node*> myQueue;
        myQueue.push(root);

        while (!myQueue.empty())
        {
            Node* currentNode = myQueue.front();
            myQueue.pop();

            std::cout << currentNode->value << " ";

            if (currentNode->left != nullptr)
            {
                myQueue.push(currentNode->left);
            }

            if (currentNode->right != nullptr)
            {
                myQueue.push(currentNode->right);
            }
        }
    }

    /**
     *  Tree Traversal: Depth-First Search (DFS) - PreOrder
     *  Function to perform Depth-First Search (DFS) traversal of a binary tree in pre-order.
     */
    void DFSPreOrder(Node* currentNode)
    {
        std::cout << currentNode->value << " ";
        if (currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            DFSPreOrder(currentNode->right);
        }
        
    }
    void DFSPreOrder() {DFSPreOrder(root);}
};


#endif //DATASTRUCTUREANDALGORITHMS_TREETRAVERSAL_H
