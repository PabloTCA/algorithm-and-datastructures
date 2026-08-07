//
// Created by Pablo Chávez on 06/08/26.
//
#include <iostream>

using namespace std;


//   +=====================================================+
//   |                 WRITE YOUR CODE HERE                |
//   | Description:                                        |
//   | - This is the Node class for key-value pairs.       |
//   | - It includes a constructor to initialize the node. |
//   | - Sets the 'key' and 'value' and sets 'next' to     |
//   |   nullptr.                                          |
//   | - Return type: N/A (constructor)                    |
//   |                                                     |
//   | Tips:                                               |
//   | - Use 'this->key' and 'this->value' to set the      |
//   |   key and value.                                    |
//   | - Initialize 'next' pointer to nullptr.             |
//   | - Check output from Test.cpp in "User logs".        |
//   +=====================================================+
class Node {
    public:
    string key;
    int value;
    Node* next;
    Node(string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        HashTable() {
            for(int i = 0; i < SIZE; i++) {
                dataMap[i] = nullptr;
            }
        }

        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }

        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << "Index " << i << ": ";
                if(dataMap[i]) {
                    cout << "Contains => ";
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "{" << temp->key << ", " << temp->value << "}";
                        temp = temp->next;
                        if (temp) cout << ", ";
                    }
                    cout << endl;
                } else {
                    cout << "Empty" << endl;
                }
            }
        }

};


