//
// Created by Pablo Chávez on 16/07/26.
//
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node* next;

    Node(int value)
    {
        this -> value = value;
        next = nullptr;
    }
};
class Stack
{
private:
    Node* top;
    int height;

public:
    Stack(int value)
    {
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }
    void printStack()
    {
        Node* temp = top;
        while (temp)
        {
            cout << temp -> value << endl;
            temp = temp -> next;
        }
    }
    void getTop()
    {
        cout << top -> value << endl;
    }
    void getHeight()
    {
        cout << height << endl;
    }
    //Functions
    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode -> next = top;
        top = newNode;
        height++;
    }
    int pop()
    {
        if (height == 0) return INT_MIN;

        Node* temp = top;
        int poppedValue = top -> value;
        top = top -> next;
        delete temp;
        height--;
        return poppedValue;
    }
};
void sortStack(stack<int>& inputStack) {
    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function sorts the input stack 'inputStack'.  |
    //   | - Uses an additional stack for sorting.              |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create an additional stack.                        |
    //   | - Pop elements from 'inputStack' and push them       |
    //   |   into 'additionalStack' in sorted order.            |
    //   | - Use a temporary variable to hold the top element   |
    //   |   of 'inputStack'.                                   |
    //   | - Move elements back to 'additionalStack' if needed. |
    //   | - Finally, move all elements back to 'inputStack'.   |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+
    if(inputStack.empty() || inputStack.size() == 1) return;
    std::stack<int> secondaryStack;
    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();
        while (!secondaryStack.empty() && secondaryStack.top() > temp)
        {
            inputStack.push(secondaryStack.top());
            secondaryStack.pop();
        }
        secondaryStack.push(temp);
    }
    while(!secondaryStack.empty()){
        inputStack.push(secondaryStack.top());
        secondaryStack.pop();
    }
}

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method adds a new value to the end of the    |
    //   |   queue (enqueue) using 'stack1'.                   |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use 'stack1' to enqueue a new value.              |
    //   | - Simply push the new value onto 'stack1'.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void enqueue(int value) {
        stack1.push(value);
    }
    void dequeue()
    {
        if (isEmpty()) return;
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        if (!stack2.empty())
        {
            stack2.pop();
            while (!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
};

class Queue
{
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int value)
    {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }
    void printQueue()
    {
        Node* temp = first;
        while (temp)
        {
            cout << temp -> value << endl;
            temp = temp -> next;
        }
    }
    void getFirst()
    {
        cout << "First: " << first -> value << endl;
    }
    void getLast()
    {
        cout << "Last: " << last -> value << endl;
    }
    void getLength()
    {
        cout << "Length: " << length << endl;
    }
    //function
    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        } else
        {
            last -> next = newNode;
            last = newNode;
        }
        length++;
    }
    int dequeue()
    {
        if (length == 0) return INT_MIN;
        Node* temp = first;
        int dequeuedValue = first -> value;
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        } else
        {
            first = first -> next;
        }
        delete temp;
        length--;
        return dequeuedValue;
    }
};