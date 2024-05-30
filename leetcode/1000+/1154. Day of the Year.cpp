static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    bool is_leap(int year) {
        if (year % 4 == 0) {
            // If divisible by 100, it must also be divisible by 400 to be a leap year
            if (year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)) {
                return true;
            }
        }
        return false;
    }
    
    int dayOfYear(string date) {
        int days = 0;

        vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int year = (date[0] - '0') * 1000 + 
                   (date[1] - '0') * 100 + 
                   (date[2] - '0') * 10 + 
                   (date[3] - '0');
        int month = (date[5] - '0') * 10 + 
                    (date[6] - '0');
        int day = (date[8] - '0') * 10 + 
                  (date[9] - '0');

        for (int i = 0; i < month - 1; i++)
            days += days_in_month.at(i);

        if (is_leap(year) && days >= 59) // jan 31 + feb 28
            days += 1;
        
        days += day;

        return days;
    }
};