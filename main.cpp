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

int main()
{
    vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5};
    vector<int> expected = {1, 2, 5};
    vector<int> result = findDuplicates(nums);
    sort(result.begin(), result.end());
}


