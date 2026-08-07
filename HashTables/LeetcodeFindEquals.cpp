//
// Created by Pablo Chávez on 05/08/26.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// COMPLEXITY O(n^2) NOT THE SOLUTION - but still works
bool itemInCommonOn2(vector<int>& a, vector<int>& b)
{
    for (auto item_a : a)
    {
        for (auto item_b : b)
        {
            if (item_a == item_b) return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////
// COMPLEXITY O(n) ACTUAL SOLUTION - Using HashTable            //
bool itemInCommon(vector<int>& vect1, vector<int>& vect2)       //
{                                                               //
    unordered_map<int, bool> myMap;                             //
    for (auto item_vect1 : vect1)                            //
    {                                                           //
        myMap.insert({item_vect1, true});               //
    }                                                           //
    for (auto item_vect2 : vect2)                            //
    {                                                           //
        if (myMap[item_vect2]) return true;                     //
    }                                                           //
    return false;                                               //
}                                                               //
//////////////////////////////////////////////////////////////////

int main()
{
    vector<int> vect1 {1, 3, 5};
    vector<int> vect2 {2, 4, 5};
    cout << itemInCommon(vect1, vect2) << endl;
}
//reconstruction