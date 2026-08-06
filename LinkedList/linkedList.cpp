//
// Created by Pablo Chávez on 21/06/26.
//
//
// Created by Pablo Chávez on 03/06/26.
//

#include <iostream>
#include <unordered_set>
using namespace std;


void printItems(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }
}

class Cookie
{
private:
    string color;
public:
    explicit Cookie(const string& color)
    {
        this -> color = color;
    }
    string getColor()
    {
        return color;
    }
    void setColor(const string& color)
    {
        this -> color = color;
    }
};

class Node
{
public:
    int value;
    Node* next;

    Node(const int value)
    {
        this -> value = value;
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
        while (temp)
        {
            head = head -> next;
            delete temp;
            temp = head;
        }
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
            tail = newNode;
        }
        length += 1;
    }
    void deleteLast()
    {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* pre = head;
            while (temp -> next)
            {
                pre = temp;
                temp = temp -> next;
            }
            tail = pre;
            tail -> next = nullptr;
        }
        delete temp;
        length--;
    }
    void deleteLast1()
    {
        if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else if (length == 0)
        {
            cout << "List is empty" << endl;
        } else
        {
            Node* temp = head;
            while (temp -> next -> next)
            {
                temp = temp -> next;
            }
            tail = temp;
            tail -> next = nullptr;
            delete tail -> next;
            --length;
        }
    }
    void prepend(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        } else
        {
            newNode -> next = head;
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
        }
        delete temp;
        length--;
    }
    Node* get(int index)
    {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp -> next;
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
        Node* temp = get(index - 1);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        length ++;
        return true;
    }
    void deleteNode(int index)
    {
        if ( index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();
        Node* pre = get(index - 1);
        Node* temp = pre -> next;
        pre -> next = temp -> next;
        delete temp;
        length --;
    }
    void reverse()
    {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* before = nullptr;
        Node* after = temp -> next;
        for (int i = 0; i < length; i++)
        {
            after = temp -> next;
            temp -> next = before;
            before = temp;
            temp = after;
        }
    }
    Node* findMiddleNode()
    {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    Node* findKthFromEnd(int k)
    {
        Node* slow = head;
        Node* fast = head;
        for (int i = 0; i< k; i++)
        {
            if (fast == nullptr) return nullptr;
            fast = fast -> next;
        }
        while (fast != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
    void removeDuplicates()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* runner = current;
            while (runner -> next != nullptr)
            {
                if (runner -> next -> value == current -> value)
                {
                    Node* temp = runner -> next;
                    runner -> next = runner -> next -> next;
                    delete temp;
                    length -= 1;
                } else
                {
                    runner = runner -> next;
                }
            }
            current = current -> next;
        }
    }
    void removeDuplicatesWithSet()
    {
        unordered_set<int> values;
        Node* previous = nullptr;
        Node* current = head;
        while (current != nullptr)
        {
            if (values.find(current -> value) != values.end())
            {
                previous -> next = current -> next;
                delete current;
                current = previous->next;
                length -= 1;
            } else
            {
                values.insert(current->value);
                previous = current;
                current = current -> next;
            }
        }
    }
    int binaryToDecimal()
    {
        Node* current = head;
        int counter = 0;
        while (current != nullptr)
        {
            counter = counter * 2 + current -> value;
            current = current -> next;
        }
        return counter;
    }
    void partitionList(int x)
    {
        if (head == nullptr || head -> next == nullptr) return;
        Node D1(0);
        Node D2(0);
        Node* prev1 = &D1;
        Node* prev2 = &D2;
        Node* current = head;
        while (current != nullptr)
        {
            if (current -> value < x)
            {
                prev1 -> next = current;
                prev1 = current;
            } else
            {
                prev2 -> next = current;
                prev2 = current;
            }
            current = current -> next;
        }
        prev2->next=nullptr;
        prev1->next = D2.next;
        head = D1.next;
    }
    void reverseBetween(int m, int n)
    {
        if (head == nullptr || head -> next == nullptr || m >= n ) return;
        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        Node* current = head;
        for (int i = 0; i < m; i++)
        {
            prev = current;
            current = current -> next;
        }
        for (int i = 0; i < n - m; i++){
            Node* toMove = current -> next;
            current -> next = toMove -> next;
            toMove -> next = prev -> next;
            prev -> next = toMove;
        }
        head = dummy.next;
    }
    void swapPairs()
    {
        if (head == nullptr || head -> next == nullptr) return;
        Node dummy(0);
        dummy.next = head;

        Node* prev = &dummy;
        Node* first = head;

        while (first != nullptr && first -> next != nullptr)
        {
            Node* second = first -> next;
            first -> next = second -> next;
            second -> next = first;
            prev -> next = second;
            prev = first;
            first = first -> next;
        }
        head = dummy.next;
    }

    void printList()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp -> value << endl;
            temp = temp -> next;
        }
    }
    void getHead() const
    {
        cout << "Head: " << head -> value << endl;
    }
    void getTail() const
    {
        cout << "Tail: " << tail -> value << endl;
    }
    void getLength() const
    {
        cout << "Length: " << length << endl;
    }

};



int main()
{
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList -> append(2);
    myLinkedList -> append(3);
    myLinkedList -> append(4);
    myLinkedList -> append(5);
    myLinkedList -> append(6);

    cout << "Original List: \n" << endl;
    myLinkedList -> printList();
    cout << "================" << endl;
    myLinkedList -> swapPairs();
    cout << "After Swap: \n" << endl;
    myLinkedList -> printList();
}

