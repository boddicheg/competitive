static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:

    std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    string reformatDate(string date)
    {
        vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string result = "";
        auto tokens = split(date, ' ');
        result += tokens[2] + "-";

        size_t idx = 0;
        for(const auto &m: months)
            if (m == tokens[1])
                break;
            else
                idx ++;

        string leading = (idx < 9) ? "0" : "";
        result += leading + std::to_string(idx + 1) + "-";

        std::string day;
        for(const auto &c: tokens[0])
            if(std::isdigit(c))
                day += c;
            else
                break;
        leading = (day.size() == 1) ? "0" : "";
        result += leading + day;

        return result;
    }
};