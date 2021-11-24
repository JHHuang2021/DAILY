#ifndef INC_20211108_1292_HPP
#define INC_20211108_1292_HPP

#include <bits/stdc++.h>

using namespace std;
int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Calendar {
private:
    int year = 0;
    int month = 0;
    int date = 0;

    bool Leap_year() const {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        else
            return false;
    }

public:
    operator string() {
        string str;
        int tmp, bit;
        tmp = year, bit = 0;
        while (tmp > 0) {
            tmp /= 10;
            bit++;
        }
        for (int i = bit + 1; i <= 4; i++)
            str += '0';
        str += (to_string(year) + '-');
        tmp = month, bit = 0;
        while (tmp > 0) {
            tmp /= 10;
            bit++;
        }
        for (int i = bit + 1; i <= 2; i++)
            str += '0';
        str += (to_string(month) + '-');
        tmp = date, bit = 0;
        while (tmp > 0) {
            tmp /= 10;
            bit++;
        }
        for (int i = bit + 1; i <= 2; i++)
            str += '0';
        str += (to_string(date));
        return str;
    }

    friend istream &operator>>(istream &input, Calendar &day) {
        day = Calendar(0, 0, 0);
        string str;
        input >> str;
        for (int i = 0; i <= 3; i++)
            day.year = 10 * day.year + str[i] - '0';
        for (int i = 5; i <= 6; i++)
            day.month = 10 * day.month + str[i] - '0';
        for (int i = 8; i <= 9; i++)
            day.date = 10 * day.date + str[i] - '0';
        return input;
    }

    friend ostream &operator<<(ostream &output, const Calendar &day) {
        int tmp, bit;
        tmp = day.year, bit = 0;
        while (tmp > 0) {
            tmp /= 10;
            bit++;
        }
        for (int i = bit + 1; i <= 4; i++)
            output << '0';
        output << day.year << '-';
        tmp = day.month, bit = 0;
        while (tmp > 0) {
            tmp /= 10;
            bit++;
        }
        for (int i = bit + 1; i <= 2; i++)
            output << '0';
        output << day.month << '-';
        tmp = day.date, bit = 0;
        while (tmp > 0) {
            tmp /= 10;
            bit++;
        }
        for (int i = bit + 1; i <= 2; i++)
            output << '0';
        output << day.date;
        return output;
    }

    Calendar() : year(1), month(1), date(1) {}

    Calendar(string str) {
        for (int i = 0; i <= 3; i++)
            year = 10 * year + str[i] - '0';
        for (int i = 5; i <= 6; i++)
            month = 10 * month + str[i] - '0';
        for (int i = 8; i <= 9; i++)
            date = 10 * date + str[i] - '0';
    }

    Calendar(const int &another_year, const int &another_month, const int &another_date) {
        year = another_year;
        month = another_month;
        date = another_date;
    }

    bool operator==(const Calendar &another_day) const {
        if (year == another_day.year && month == another_day.month && date == another_day.date)
            return true;
        else
            return false;
    }

    bool operator!=(const Calendar &another_day) const {
        if (*this == another_day)
            return false;
        else
            return true;
    }

    bool operator<(const Calendar &another_day) const {
        if (year == another_day.year) {
            if (month == another_day.month) {
                if (date == another_day.date)
                    return false;
                else return date < another_day.date;
            } else return month < another_day.month;
        } else return year < another_day.year;
    }

    bool operator>(const Calendar &another_day) const {
        return another_day < *this;
    }

    bool operator<=(const Calendar &another_day) const {
        if (*this > another_day)
            return false;
        else
            return true;
    }

    bool operator>=(const Calendar &another_day) const {
        if (*this < another_day)
            return false;
        else
            return true;
    }

    Calendar &operator++() {
        if (month == 2) {
            if (Leap_year() && date <= 28 || date <= 27)
                date++;
            else {
                month++;
                date = 1;
            }
            return *this;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (date <= 29)
                date++;
            else {
                month++;
                date = 1;
            }
        } else if (month == 12) {
            if (date <= 30)
                date++;
            else {
                month = 1;
                date = 1;
                year++;
            }
        } else {
            if (date <= 30)
                date++;
            else {
                date = 1;
                month++;
            }
        }
        return *this;
    }

    Calendar operator++(int x) {
        Calendar tmp = *this;
        ++*this;
        return tmp;
    }

    Calendar &operator--() {
        if (month == 3) {
            if (date == 1) {
                month--;
                if (Leap_year())
                    date = 29;
                else
                    date = 28;
            } else {
                date--;
            }
            return *this;
        } else if (month == 5 || month == 7 || month == 10 || month == 12) {
            if (date >= 2)
                date--;
            else {
                month--;
                date = 30;
            }
        } else if (month == 1) {
            if (date >= 2)
                date--;
            else {
                month = 12;
                date = 31;
                year--;
            }
        } else {
            if (date >= 2)
                date--;
            else {
                date = 31;
                month--;
            }
        }
        return *this;
    }

    Calendar operator--(int x) {
        Calendar tmp = *this;
        --*this;
        return tmp;
    }

    Calendar &operator+=(int x) {
        for (int i = 1; i <= x; i++)
            ++*this;
        return *this;
    }

    Calendar &operator-=(int x) {
        for (int i = 1; i <= x; i++)
            --*this;
        return *this;
    }

    Calendar operator+(int x) {
        Calendar tmp = *this;
        tmp += x;
        return tmp;
    }

    Calendar operator-(int x) {
        Calendar tmp = *this;
        tmp -= x;
        return tmp;
    }

    Calendar &operator=(const Calendar &another_day) {
        year = another_day.year;
        month = another_day.month;
        date = another_day.date;
        return *this;
    }

    int operator-(const Calendar &another_day) {
        int day_int = 0, another_day_int = 0;
        day_int += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
        for (int i = 1; i <= month - 1; i++)
            day_int += month_day[i];
        day_int += date;
        if (month >= 3 && Leap_year())
            day_int++;

        another_day_int += (another_day.year - 1) * 365 + (another_day.year - 1) / 4 - (another_day.year - 1) / 100 +
                           (another_day.year - 1) / 400;
        for (int i = 1; i <= another_day.month - 1; i++)
            another_day_int += month_day[i];
        another_day_int += another_day.date;
        if (another_day.month >= 3 && another_day.Leap_year())
            another_day_int++;
        return day_int - another_day_int;
    }

    int getday() {
        int day_int = 0;
        day_int += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
        for (int i = 1; i <= month - 1; i++)
            day_int += month_day[i];
        day_int += date;
        if (month >= 3 && Leap_year())
            day_int++;
        return day_int % 7;
    }
};

Calendar operator "" _C(const char *col, size_t n) {
    string str(col);
    Calendar one_day(str);
    return one_day;
}

#endif //INC_20211108_1292_HPP
