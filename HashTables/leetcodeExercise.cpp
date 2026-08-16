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
 *
 *  --------------------------------- Actual Solution from the lesson --------------------------------------------------
 *      vector<int> findDuplicates(const vector<int>& nums) {
        unordered_map<int, int> numCounts;
        for (int num : nums) {
            numCounts[num]++;
        }
        vector<int> duplicates;
        for (const auto& entry : numCounts) {
            if (entry.second > 1) {
                duplicates.push_back(entry.first);
            }
        }
        return duplicates;
    }
 *
 */
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
 * This exercise took me like 3 hours I really didn't know that I could create a
 * Map with vectors like the <string, vector<string>> and end up making multiple loops for nothing,
 * I was about to loose all hope TT-TT
 */
vector<vector<string>> groupAnagrams(vector<string>& str)
{
    unordered_map<string, vector<string>> anagramMap;
    for (auto& s : str)
    {
        string word = s;
        sort(word.begin(), word.end());
        anagramMap[word].push_back(s);
    }
    vector<vector<string>> groupAnagrams;
    groupAnagrams.reserve(anagramMap.size());
    for (auto& word : anagramMap)
    {
        groupAnagrams.push_back(word.second);
    }
    return groupAnagrams;
}

/*
 * This one was hard yoo, well I also didn't had much time this week to put all my mind into the exercise u.u
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

/**
 *
 * @param nums a vector of integers
 * @param target the target sum
 * @return a vector containing the indices of the two numbers that add up to the target
 *
 * I was able to get soo close to the solution with my pseudocode, but I couldn't figure out how to implement it.
 * In the end I had to use a lot of help from the internet to solve this exercise and from the hints in the exercise.
 * But after looking at the solution, I was able to understand it better.
 */
vector<int> subarraySum(const vector<int>& nums, int target)
{
    std::unordered_map<int, int> sumIndex;
    sumIndex[0] = -1;
    int currentSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        if(sumIndex.find(currentSum - target) != sumIndex.end()){
            return {sumIndex[currentSum - target] + 1, i};
        }
        sumIndex[currentSum] = i;
    }
    return {};
}

int main()
{
    // vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5};
    // vector<int> expected = {1, 2, 5};
    // vector<int> result = findDuplicates(nums);
    // sort(result.begin(), result.end());
    //
    // string input = "aabbcc";
    // char result = firstNonRepeatingChar(input);
    // std::cout << result << std::endl;

    // std::string sort_string = "eat";
    // sort_string = sort_string.substr(0, sort_string.length() - 1);
    // std::cout << sort_string << std::endl;

}


