// https://leetcode.com/problems/two-sum/description/

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