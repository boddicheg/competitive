class Solution {
public:
    string convert(string s, int numRows) {
        string result{};
 
        int string_idx = 0;
        vector<string> m(numRows, "");
        while(string_idx < s.size())
        {
            for(int j = 0; j < numRows && string_idx < s.size(); j++, string_idx++)
                m[j] += s.at(string_idx);

            for(int j = numRows - 2; j > 0 && string_idx < s.size(); j--, string_idx++)
                m[j] += s.at(string_idx);
        }

        for(auto& row: m)
            result += row;

        return result;
    }
};