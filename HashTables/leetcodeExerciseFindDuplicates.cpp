//
// Created by Pablo Chávez on 08/08/26.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(const vector<int>& nums)
{
    vector<int> duplicates;
    unordered_map<int, bool> duplicated_map;
    for (auto num : nums)
    {
        if (duplicated_map[num])
        {
            duplicates.push_back(num);
        } else
        {
            duplicated_map[num] = true;
        }
    }
    return duplicates;
}

/**
 * Just to remember:
 * I was having a hard time making it work correctly because I had this bug:
 * Whenever I want to compare if it was already in the map it always answered no, thats because the way I was comparing
 * it, so Now I now, that whenever comparing with map[i] this will create the entry as false, so when I wanted to insert
 * a new value or create the entry, well the entry was already created in the comparison, in the if as False,
 * so doing duplicated_map.insert({num, true}); does nothing because the key already exist, but as false, so that was
 * the lesson, the [] if the entry does not exist it creates it as false.
 *
 * The solution for my bug was just look for it again and assign it true -> duplicated_map[num] = true;
 *  LMAO
 */



int main()
{
    vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5};
    vector<int> expected = {1, 2, 5};
    vector<int> result = findDuplicates(nums);
    sort(result.begin(), result.end());
}


