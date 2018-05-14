// https://www.codingame.com/ide/puzzle/chuck-norris

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    std::string MESSAGE;
    std::getline(std::cin, MESSAGE);

    std::string result;

    std::string binaryRepresentation;
    for(size_t i = 0; i < MESSAGE.size(); i++) {
        std::bitset<7> mes(MESSAGE.at(i));
        std::string binary = mes.to_string();
        binaryRepresentation.append(binary);
    }
    std::vector<std::string> subSequences;
    std::string subSequence;
    char currentSymbol = binaryRepresentation.at(0);
    for(size_t i = 0; i < binaryRepresentation.size(); i++) {
        auto symbol = binaryRepresentation.at(i);
        if (symbol != currentSymbol) {
            subSequences.push_back(subSequence);
            subSequence.clear();
            subSequence += symbol;
            currentSymbol = symbol;
        } else {
            subSequence += symbol;
        }
    }
    if (!subSequence.empty()) {
        subSequences.push_back(subSequence);
    }

    for(size_t i = 0; i < subSequences.size(); i++) {
        std::string s = subSequences.at(i);
        if (s.at(0) == '1') {
            result += "0 ";
            result += std::string(s.size(), '0');
        }
        if (s.at(0) == '0') {
            result += "00 ";
            result += std::string(s.size(), '0');

        }
        if (i != subSequences.size() - 1) {
            result += " ";
        }

    }

    std::cout << result << std::endl;
}