// https://leetcode.com/problems/two-sum/description/

// Bruteforce - Runtime: 170ms
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(size_t i = 0; i < nums.size(); ++i)
        {
            for(size_t j = 0; j < nums.size(); ++j)
            {
                if(nums.at(i) + nums.at(j) == target && i != j)
                {
                    return { i, j };
                }
            }
        }
    }
};

// Fast - Runtime: 9 ms
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::map<int, int> pairs;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int first = nums.at(i);
            auto it = pairs.find(target - first);
            if (it != pairs.end() && it->second != i)
                return {i, it->second};
            else
                pairs[first] = i;
        }
    }
};