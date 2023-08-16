class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        for(int give = 0; candies > 0; candies -= ++give)
            result[give % num_people] += std::min(candies, give + 1);

        return result;
    }
};