#include <iostream>
#include <vector>
#include <map>
using namespace std;

std::map<char, int> datamap =
{
    { 'q', 0 },
    { 'w', 0 },
    { 'e', 0 },
    { 'r', 0 },
    { 't', 0 },
    { 'y', 0 },
    { 'u', 0 },
    { 'i', 0 },
    { 'o', 0 },
    { 'p', 0 },
    { 'a', 1 },
    { 's', 1 },
    { 'd', 1 },
    { 'f', 1 },
    { 'g', 1 },
    { 'h', 1 },
    { 'j', 1 },
    { 'k', 1 },
    { 'l', 1 },
    { 'z', 2 },
    { 'x', 2 },
    { 'c', 2 },
    { 'v', 2 },
    { 'b', 2 },
    { 'n', 2 },
    { 'm', 2 }
};

vector<string> findWords(vector<string> &words)
{
    std::vector<std::string> result;

    for (const auto &word : words)
    {
        bool from_one_row = true;
        int current = -1;
        for (const auto &letter : word)
        {
            char low_letter = std::tolower(letter);
            if (current == -1 ) current = datamap[low_letter];
            else
            {
                if (current != datamap[low_letter])
                {
                    from_one_row = false;
                    break;
                }
            }
        }
        if (from_one_row)
            result.push_back(word);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<string> data = {"Hello", "Alaska", "Dad", "Peace"};
    auto result = findWords(data);
    for (const auto &word : result)
        std::cout << word << " " ;
    std::cout << std::endl;
    return 0;
}