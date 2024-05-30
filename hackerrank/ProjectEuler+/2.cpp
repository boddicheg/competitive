#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        /*
        int first = 2;
        int second = 8;
        int sum = 10;
        while (true)
        {
            int next = first + 4 * second;
            if (next >= n) 
            {
                std::cout << sum << std::endl;
                break;
            }
            sum += next;
            first = second;
            second = next;
        }
        */
        vector<long long> even_fibs = {2, 8, 34, 144, 610, 2584, 10946, 46368, 196418, 832040, 3524578, 14930352, 63245986, 267914296, 1134903170,
          4807526976, 20365011074, 86267571272, 365435296162, 1548008755920, 6557470319842, 27777890035288,
          117669030460994, 498454011879264, 2111485077978050, 8944394323791464, 37889062373143906};
        
        long long sum = 0;
        for (const auto& f: even_fibs)
        {
            if (n < f)
                break;
            sum += f;
        }

        std::cout << sum << std::endl;
    }
    return 0;
}
