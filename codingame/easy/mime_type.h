// https://www.codingame.com/ide/puzzle/mime-type

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    std::map<std::string, std::string> table;
    std::vector<std::string> results;
    int N; // Number of elements which make up the association table.
    std::cin >> N; std::cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    std::cin >> Q; std::cin.ignore();
    for (int i = 0; i < N; i++)
    {
        std::string EXT; // file extension
        std::string MT; // MIME type.
        std::cin >> EXT >> MT; std::cin.ignore();
        for (size_t j = 0; j < EXT.size(); j++)
            EXT.at(j) = std::tolower(EXT.at(j));
        table.insert(std::pair<std::string, std::string>(EXT, MT));
    }
    for (int i = 0; i < Q; i++)
    {
        std::string FNAME; // One file name per line.
        std::getline(std::cin, FNAME);
        std::string extention(FNAME.begin() + FNAME.find_last_of(".") + 1, FNAME.end());
        for (size_t j = 0; j < extention.size(); j++)
            extention.at(j) = std::tolower(extention.at(j));
        auto it = table.find(extention);
        if (it != table.end() && FNAME.find_last_of(".") < FNAME.size())
            results.push_back(it->second); else
            results.push_back("UNKNOWN");
    }
    for (int i = 0; i < results.size(); i++)
        std::cout << results.at(i) << std::endl;
}