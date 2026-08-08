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

int main()
{
    string input = "aabbcc";
    char result = firstNonRepeatingChar(input);
    std::cout << result << std::endl;
}


