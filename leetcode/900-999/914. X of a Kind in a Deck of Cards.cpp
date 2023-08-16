static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    int gcd(int x, int y)
    {
        return (x == 0) ? y : gcd(y % x, x);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        std::map<int, int> mapped;

        for(auto &&d: deck)
            mapped[d] ++;
        
        int divider = -1;
        for(auto &&e: mapped)
        {
            if (divider == -1)
                divider = e.second;
            else
                divider = gcd(divider, e.second);
        }

        return divider >= 2;
    }
};