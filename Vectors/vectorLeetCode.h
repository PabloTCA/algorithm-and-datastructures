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

    static int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int writePointer = 1;

        for (int readPointer = 1; readPointer < nums.size(); readPointer++)
        {
            if (nums[readPointer] != nums[readPointer - 1])
            {
                nums[writePointer] = nums[readPointer];
                writePointer++;
            }
        }
        return writePointer;
    }

    static int maxProfit(std::vector<int>& prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices)
        {
            minPrice = std::min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = std::max(maxProfit, profit);
        }
        return maxProfit;
    }

    static void rotate(std::vector<int>& nums, int k)
    {
        if (nums.empty()) return;

        k %= nums.size();

        for (int start = 0, end = nums.size() - k - 1; start < end; start++, end--)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
        for (int start = nums.size() - k, end = nums.size() - 1; start < end; start++, end--)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
        for (int start = 0, end = nums.size() - 1; start < end; start++, end--)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
    }
};


#endif //DATASTRUCTUREANDALGORITHMS_VECTORLEETCODE_H
