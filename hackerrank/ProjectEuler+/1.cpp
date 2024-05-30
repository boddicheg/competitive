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

long long sum(long long n, long long k)
{
    return k * (n / k) * (n / k + 1) / 2;
}

int main(){
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        n--;
        cout << sum(n, 3) + sum(n, 5) - sum(n, 15) << std::endl;
    }
    return 0;
}