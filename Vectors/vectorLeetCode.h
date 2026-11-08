//
// Created by Pablo Chávez on 04/11/26.
//
#ifndef DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H
#define DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H


#include <vector>
#include <string>

class vectorLeetCode
{
public:
    static void removeElement(std::vector<int>&nums, int val)
    {
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        nums.resize(i);
    }

    static std::vector<int> findMaxMin(const std::vector<int>& myList)
    {
        if (myList.empty()) return {};
        int max = myList[0], min = myList[0];

        for (int i = 1; i < myList.size(); i++)
        {
            if (myList[i] >= max) max = myList[i];
            else if (myList[i] <= min) min = myList[i];
        }
        return {max, min};
    }
    static std::string findLongestString(std::vector<std::string>& stringList )
    {
        std::string longest_string;
        for (auto& str : stringList)
        {
            if (str.length() > longest_string.length())
            {
                longest_string = str;
            }
        }
        return longest_string;
    }
};


#endif //DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H
