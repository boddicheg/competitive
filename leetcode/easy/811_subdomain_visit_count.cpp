#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

std::vector<std::string> subdomainVisits(std::vector<std::string> &cpdomains)
{
    std::map<std::string, int> db;

    for (auto cpdomain : cpdomains)
    {
        std::stringstream ss(cpdomain);
        // Getting number
        std::string buffer;
        std::getline(ss, buffer, ' ');
        int visitors = std::stoi(buffer);
        // Getting domains
        std::string address;
        std::getline(ss, address, ' ');

        size_t first_found_idx = 0;
        while (true)
        {
            std::string top_lvl_domain = address.substr(first_found_idx, address.size());
            // Add to database
            if (db.find(top_lvl_domain) != db.end())
                db.at(top_lvl_domain) += visitors;
            else
                db[top_lvl_domain] = visitors;
            // Prepare index
            first_found_idx = address.find_first_of('.', first_found_idx);
            if (first_found_idx == std::string::npos)
                break;
            else
                first_found_idx++;
        }
    }

    std::vector<std::string> result;

    for (const auto &p : db)
        result.push_back(std::to_string(p.second) + " " + p.first);

    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> data = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    auto result = subdomainVisits(data);
    for (const auto &val : result)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}