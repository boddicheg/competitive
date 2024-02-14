class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;

        int control_map[26] = {0};
        for(char c: chars)
            control_map[c - 'a'] ++;

        for(auto word: words)
        {
            int current[26] = {0};
            for(char c: word)
                current[c - 'a'] ++;
            bool accepted = true;
            for(int i{0}; i < 26; i++)
            {
                if (control_map[i] < current[i])
                {
                    accepted = false;
                    break;
                }
            }
            if (accepted)
                sum += word.size();
        }
        
        return sum;
    }
};