//
// Created by Pablo Chávez on 17/08/26.
//
#include <iostream>
#include <unordered_set>

using std::string, std::unordered_set;

int main()
{
    //Creating a set
    unordered_set<string> myStringSet = {"F-18", "F-14", "F-16", "F-22", "F-35"};

    //Adding elements to my set
    myStringSet.insert("Su-35");
    myStringSet.insert("Su-33");
    myStringSet.insert("Su-47");

    std::cout << "Before erasing:\n";
    for (auto& element : myStringSet)
    {
        std::cout << element << '\n';
    }

    //Erase items from my set;
    myStringSet.erase("Su-35");
    myStringSet.erase("F-35");

    std::cout << "After erasing:\n";
    for (auto& element : myStringSet)
    {
        std::cout << element << '\n';
    }

    // Check if an element exist in the set
    if (myStringSet.find("F-22") != myStringSet.end())
    {
        std::cout << "F-22 exists in the set\n";
    } else
    {
        std::cout << "F-22 does not exist in the set\n";
    }

    // Find the size of the set
    std::cout << "The size of the set is: " << myStringSet.size() << '\n';

    // Check if the set is empty
    if (myStringSet.empty())
    {
        std::cout << "The set is empty\n";
    } else
    {
        std::cout << "The set is not empty\n";
    }

    // Clear all the elements in the set
    myStringSet.clear();

    // Check if the set is empty after clearing
    std::cout << "Size after clearing: " << myStringSet.size() << std::endl;


}