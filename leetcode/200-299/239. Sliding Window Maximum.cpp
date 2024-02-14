class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;
        std::deque<int> dq;
        for(int i{0}; i < nums.size(); i++)
        {
            while(!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            while(!dq.empty() && nums.at(dq.back()) < nums.at(i))
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1)
                result.push_back(nums.at(dq.front()));
        }

        return result;
    }
};