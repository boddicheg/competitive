#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

// TODO: POLISH NOTATION
class Solution {
private:
    char TRUE = 't';
    char FALSE = 'f';
    char NOT = '!';
    char AND = '&';
    char OR = '|';
public:
    bool parseBoolExpr(string expression) {
        return parse(expression, 0);
    }

    string generateTab(int times)
    {
        string res;
        for (size_t i = 0; i < times; i++)
            res += '\t';
        return res;
    }

    vector<string> split(string s, char delimeter)
    {
        std::vector<std::string> result; 
        int ignore_del = 0;
        string buffer;

        for(auto &&e: s)
        {
            if (e == '(')
                ignore_del++;

            if (e == ')')
                ignore_del--;

            if (e == delimeter)
            {
                if (ignore_del > 0)
                {
                    buffer += e;
                }
                else
                {
                    result.push_back(buffer);
                    buffer = "";
                }
            }
            else
                buffer += e;
        }

        result.push_back(buffer);

        return result;
    }

    bool parse(string e, int tab_times)
    {
        string tabs = generateTab(tab_times);
        std::cout << "-> " << tabs << e << std::endl;

        if (e == (string() + TRUE))
            return true;

        if (e == (string() + FALSE))
            return false;

        if (e.at(0) == NOT)
        {
            int start_pos = e.find_first_of('(');
            int end_pos = e.find_last_of(')');
            string inner(e.begin() + start_pos + 1, e.begin() + end_pos);
            return ! parse(inner, tab_times + 1);
        }

        if (e.at(0) == OR)
        {
            int start_pos = e.find_first_of('(');
            int end_pos = e.find_last_of(')');
            string inner(e.begin() + start_pos + 1, e.begin() + end_pos);

            // std::cout << "OR inner: [" << (start_pos + 1) << "," << end_pos << "] " << inner  << std::endl;

            auto exprs = split(inner, ',');
            // std::cout << "OR exprs: " << exprs.size() << std::endl;

            bool res = false;

            for(auto && e: exprs)
                res |= parse(e, tab_times + 1);

            return res;
        }

        if (e.at(0) == AND)
        {
            int start_pos = e.find_first_of('(');
            int end_pos = e.find_last_of(')');
            string inner(e.begin() + start_pos + 1, e.begin() + end_pos);

            auto exprs = split(inner, ',');
            // std::cout << "AND exprs: " << exprs.size() << std::endl;
            bool res = true;

            for(auto && e: exprs)
                res &= parse(e, tab_times + 1);

            return res;
        }

        throw std::runtime_error("Not implemented!");
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {};
    bool result;
    vector<string> expr = {
        // "f",
        // "t",
        // "!(f)",
        // "!(t)",
        // "|(t,f)",
        // "|(t,t)",
        // "|(f,f)",
        // "|(!(f),!(f))",
        // "&(t,f)",
        // "&(t,t)",
        // "|(&(f,f,f,t),f)",
        // "|(&(t,f,t),!(t))",
        // "&(!(f),!(t))",
        // "|(&(t,f,t),!(t))"
        "&(t,t,t)"
    };

    for( auto e: expr)
    {
        result = s.parseBoolExpr(e);
        std::cout << e << " ->  " << result << std::endl;
    }

    return 0;
}
