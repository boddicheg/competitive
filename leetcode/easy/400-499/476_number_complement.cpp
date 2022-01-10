#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

// Both 6 ms

int findComplement(int num) {
    int result = 0;
    int i = 0;
    while(num)
    {
        result |= !(num & 1) << i++;
        num >>= 1;
    }
    return result;
}

int findComplement1(int num) {
    bitset<32> b(num);
    std::string bit_repr = b.to_string();
    bit_repr.erase(0, bit_repr.find_first_not_of('0'));
    for(auto& c: bit_repr)
        c = (c == '1') ? '0' : '1';
    std::bitset<32> result(bit_repr);
    return result.to_ulong();
}

int main(int argc, char const *argv[])
{
    findComplement(5);
    findComplement1(5);
    return 0;
}