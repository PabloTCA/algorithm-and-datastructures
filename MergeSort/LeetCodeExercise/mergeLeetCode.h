//
// Created by Pablo Chávez on 21/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_MERGELEETCODE_H
#define DATASTRUCTUREANDALGORITHMS_MERGELEETCODE_H
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~LinkedList()
    {
        Node* temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void printList()
    {
        Node* temp = head;
        if (temp == nullptr)
        {
            cout << "empty";
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr)
                {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }
    Node* getHead()
    {
        return head;
    }
    Node* getTail()
    {
        return tail;
    }
    int getLength()
    {
        return length;
    }
    void append(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        } else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void deleteFirst()
    {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        } else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    // LEET CODE merge function
    void merge(LinkedList& otherList)
    {
        Node* otherHead = otherList.getHead();
        Node* dummy = new Node(0);
        Node* current = dummy;
        while (head != nullptr && otherHead != nullptr)
        {
            if (head->value < otherHead->value)
            {
                current->next = head;
                head = head->next;
            } else
            {
                current->next = otherHead;
                otherHead = otherHead->next;
            }
            current = current->next;
        }
        if (head != nullptr)
        {
            current->next = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
        } else
        {
            current->next = otherHead;
            while (current->next != nullptr)
            {
                current = current->next;
            }
        }
        tail = current;
        head = dummy->next;
        delete dummy;
        length += otherList.getLength();
        otherList.head = nullptr;
        otherList.tail = nullptr;
        otherList.length = 0;
    }
};


#endif //DATASTRUCTUREANDALGORITHMS_MERGELEETCODE_H
