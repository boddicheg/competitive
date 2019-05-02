#include <string>
#include <sstream>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string s)
    {
        std::stringstream ss(s);
        std::string tmp;
        std::string result;
        while(ss >> tmp)
        {
            result += std::string(tmp.rbegin(), tmp.rend());
            if(!ss.eof())
                result += " ";
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverseWords("qwe asd zxc") << std::endl;
    return 0;
}
