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

char firstNonRepeatingChar(const string& input_string) {
    std::unordered_map<char, int> charCount;
    for (char c : input_string){
        charCount[c]++;
    }
    for (const char& c : input_string){
        if(charCount[c] == 1)
        {
            return c;
        }
    }
    return '\0';
}

/*
 * This one was hard yoo, well I also didin't had much time this week to put all my mind into the exercise u.u
 * Hope next week I can have more time. At the end I had to use a lot of help from the internet to solve this exercise
 * and from the hints in the exercise. *sad*
 *
 */

vector<int> twoSum(const vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        std::cout << numMap.find(complement)->second << '\n';
        const auto& pair = numMap.find(complement);
        if (pair != numMap.end())
        {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}
int main()
{

}


