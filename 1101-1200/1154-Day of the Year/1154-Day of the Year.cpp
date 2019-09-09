class Solution {
public:
    int dayOfYear(string date) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)),
            day = stoi(date.substr(8, 2));
        int result = day;
        if (month > 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            ++result;
        }

        while (--month > 0) {
            result += days[month - 1];
        }

        return result;
    }
};
