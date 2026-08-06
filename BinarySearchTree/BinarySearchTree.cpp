//
// Created by Pablo Chávez on 02/08/26.
//
using namespace std;
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
    bool contains(int value)
    {
        //We could add this constrain but it's not require because even without it, it'll work perfectly fine.
        // if (root == nullprt) return false
        Node* temp = root;
        while (temp)
        {
            if (value < temp -> value)
            {
                temp = temp -> left;
            } else if (value > temp -> value)
            {
                temp = temp -> right;
            } else
            {
                return true;
            }
        }
        return false;
    }
};