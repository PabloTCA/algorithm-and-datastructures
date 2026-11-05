//
// Created by Pablo Chávez on 04/11/26.
//
#include <vector>
#ifndef DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H
#define DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H


class vectorLeetCode
{
public:
    void removeElement(std::vector<int>&nums, int val)
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

    std::vector<int> findMaxMin(const std::vector<int>& myList)
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
};


#endif //DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H
