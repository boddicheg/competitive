#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int calPoints(vector<string> &ops)
{
    std::stack<int> points;

    for (const auto &operation : ops)
    {
        if (operation == "C") points.pop();
        else if (operation == "D")
        {
            int last_round_score = points.top();
            points.pop();
            points.push(last_round_score);
            points.push(last_round_score * 2);
        }
        else if (operation == "+")
        {
            int last_round_score = points.top();
            points.pop();
            int prev_last_round = points.top();
            // points.pop();
            points.push(last_round_score);
            points.push(last_round_score + prev_last_round);
        }
        else
        {
            int score = std::stoi(operation);
            points.push(score);
        }
    }

    int summary = 0;
    while (!points.empty())
    {
        summary += points.top();
        points.pop();
    }
    return summary;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> data =
    {
        // "5","2","C","D","+"
        "5", "-2", "4", "C", "D", "9", "+", "+"
    };
    int result = calPoints(data);
    std::cout << result << std::endl;
    return 0;
}