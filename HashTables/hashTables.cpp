//
// Created by Pablo Chávez on 05/08/26.
//
#include <iostream>
using namespace std;

// HASH TABLES
class Node
{
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];
public:
    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ":" << endl;
            if (dataMap[i])
            {
                Node* temp = dataMap[i];
                while (temp)
                {
                    cout << "  {" << temp->key << ", " << temp->value <<"}" << endl;
                    temp = temp->next;
                }
            }
        }
    }
    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            const int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % (SIZE);
        }
        return hash;
    }
    void set(string key, int value)
    {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        } else
        {
            Node* temp = dataMap[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    int get(string key)
    {
        int index = hash(key);
        Node* temp = dataMap[index];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }
    vector<string> keys()
    {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++)
        {
            Node* temp = dataMap[i];
            while (temp != nullptr)
            {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
};



int main()
{
   HashTable* myHT = new HashTable();
    myHT->set("nails",100);
    myHT->set("tile",50);
    myHT->set("lumber",80);

    myHT->set("bolts",200);
    myHT->set("screw",140);
    myHT->printTable();
    cout << myHT->get("lumber") << endl;
    vector<string> myKeys = myHT->keys();
    for (auto key : myKeys)
    {
        cout << "My key: " << key << endl;
    }
}