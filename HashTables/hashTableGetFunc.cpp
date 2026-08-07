//
// Created by Pablo Chávez on 06/08/26.
//
#include <iostream>

using namespace std;


class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue *  23) % SIZE;
            }
            return hash;
        }

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

        void set(string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if (dataMap[index] == nullptr) {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This method retrieves the value for a given key.  |
        //   | - It first hashes the key to find the index.        |
        //   | - Searches through the linked list at that index.   |
        //   | - Return type: int                                  |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Use the 'hash' function to get the index.         |
        //   | - Use a while loop to traverse the linked list.     |
        //   | - If the key matches, return the value.             |
        //   | - If the key is not found, return 0.                |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        int get(string key){
            int index = hash(key);
            Node* temp = dataMap[index];
            while (temp != nullptr){
                if (temp->key == key){
                    return temp->value;
                }
                temp = temp->next;
            }
            return 0;
        }
};


