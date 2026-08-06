#include <iostream>
//
// Created by Pablo Chávez on 14/07/26.
//
class Node
{
public:
    int value;
    Node* next;
    Node* prev;
    Node(int value)
    {
        this -> value = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    DoublyLinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    void printList()
    {
        Node* temp = head;
        while (temp)
        {
            std::cout << temp -> value << std::endl;
            temp = temp -> next;
        }
    }
    void getHead()
    {
        std::cout << head -> value << std::endl;
    }
    void getTail()
    {
        std::cout << tail -> value << std::endl;
    }
    void getLength()
    {
        std::cout << length << std::endl;
    }
    void append(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
           head = newNode;
            tail = newNode;
        }else
        {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        length++;
    }
    void deleteLast()
    {
        if (length == 0) return;
        Node* temp = tail;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }else
        {
            tail =tail->prev;
            tail -> next = nullptr;
        }
        delete temp;
        length--;
    }
    void prepend(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }else
        {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
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
        }else
        {
            head = head -> next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }
    Node* get(int index)
    {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp -> next;
            }
        } else
        {
            for (int i = length - 1; i > index; i--)
            {
                temp = temp -> prev;
            }
        }
        return temp;
    }
    bool set(int index, int value)
    {
        Node* temp = get(index);
        if (temp)
        {
            temp -> value = value;
            return true;
        }
        return false;
    }
    bool insert(int index, int value)
    {
        if (index < 0 || index > length) return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;

        newNode -> prev = before;
        newNode -> next = after;
        before -> next = newNode;
        after -> prev = newNode;
        length++;
    }
    // void deleteNode(int index)
    // {
    //     if ( index < 0 || index > length - 1) return;
    //     if ( index == 0 ) return deleteFirst();
    //     if ( index == length - 1 ) return deleteLast();
    //     Node* before = get(index - 1);
    //     Node* temp = before -> next;
    //     Node* after = temp -> next;
    //     delete temp;
    //     before -> next = after;
    //     after -> prev = before;
    //     length--;
    // }
    void deleteNode(int index)
    {
        if ( index < 0 || index > length - 1) return;
        if ( index == 0 ) return deleteFirst();
        if ( index == length - 1 ) return deleteLast();
        Node* temp = get(index);
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        delete temp;
        length--;
    }
    void reverse()
    {
        if (length <= 1) return;
        Node* current = head;
        Node* temp = current -> prev;
        while (current != nullptr)
        {
            current -> prev = current -> next;
            current -> next = temp;
            temp = current;
            current = current -> prev;
        }
        tail = head;
        head = temp;
    }
    void partitionList(int x)
    {
        if (head == nullptr || head -> next == nullptr) return;
        Node dummy1(0);
        Node dummy2(0);
        Node* prev1 = &dummy1;
        Node* prev2 = &dummy2;
        Node* current = head;
        while (current != nullptr)
        {
            if (current -> value < x)
            {
                prev1 -> next = current;
                prev1 = current;
            }
            else
            {
                prev2 -> next = current;
                prev2 = current;
            }
            current = current -> next;
        }
        if (dummy1.next == nullptr || dummy2.next == nullptr) return;
        Node* temp1 = dummy1.next;
        Node* temp2 = dummy2.next;
        temp1 -> prev = nullptr;
        temp2 -> prev = prev1;
        prev1 -> next = temp2;
        prev2 -> next = nullptr;
    }
    void reverseBetween (int startIndex, int endIndex)
    {
        if (head == nullptr || startIndex == endIndex) return;
        Node* dummy = new Node(0);
        dummy -> next = head;
        head -> prev = dummy;
        Node* prev = dummy;
        // Node* current = head;
        for (int i = 0; i < startIndex; i++)
        {
            prev = prev -> next;
        }
        Node* current = prev -> next;
        for (int i = 0; i < endIndex - startIndex; i++)
        {
            Node* nodeToMove = current -> next;

            current -> next = nodeToMove -> next;
            if (nodeToMove->next)
            {
                nodeToMove -> next -> prev = current;
            }

            nodeToMove -> next = prev -> next;
            prev -> next -> prev = nodeToMove;
            prev -> next = nodeToMove;
            nodeToMove -> prev = prev;
        }
        head = dummy -> next;
        head -> prev = nullptr;
        delete dummy;
    }
    void swapPairs()
    {
        if (head == nullptr || head -> next == nullptr) return;
        Node* dummy = new Node(0);
        dummy -> next = head;
        head -> prev = dummy;
        Node* prev = dummy;
        Node* current = head;
        while (current != nullptr && current -> next != nullptr)
        {
            Node* after = current -> next;
            current -> next = after -> next;
            if (after -> next != nullptr)
            {
                after -> next -> prev = current;
            }
            after -> next = prev -> next;
            current -> prev = after;
            after -> prev = prev;
            prev -> next = after;

            prev = current;
            current = current -> next;
        }
        head = dummy -> next;
        head -> prev = nullptr;
        delete dummy;
    }
};

