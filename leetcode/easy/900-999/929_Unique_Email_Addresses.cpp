#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    int numUniqueEmails(const std::vector<std::string>& emails)
    {
        for(const auto& mail : emails)
        {
            size_t sign = mail.find_first_of('@');
            std::string local_name;
            for(size_t i = 0; i < sign; i++)
            {
                char letter = mail.at(i);
                if (letter == '.') continue;
                if (letter == '+') break;
                local_name += letter;
            }
            matches.insert(local_name + std::string(mail.begin() + sign, mail.end()));
        }
        return matches.size();
    }

private:
    std::unordered_set<std::string> matches;
};

int main(int argc, char const *argv[])
{
    Solution s;
    //auto result = s.numUniqueEmails({"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" });
    auto result = s.numUniqueEmails({"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"});

    std::cout << result << std::endl;
    return 0;
}