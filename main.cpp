#include <iostream>

using namespace std;

class Date {
private:
    int year, month, day, hour, minute, second;
    bool isOurEra;

    static int daysInMonth(int year, int month) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
                break;
            default:
                return isLeapYear(year) ? 29 : 28;
                break;
        }
    }

    static bool isLeapYear(int year) {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }

public:
    // По дефолту
    Date() {
        this->year = 1960;
        this->month = 1;
        this->day = 1;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
        this->isOurEra = true;
    }

    // С параметрами
    Date(int year, int month, int day, int hour, int minute, int second, bool isOurEra) {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
        this->isOurEra = isOurEra;
    }

    // Дубликат
    Date(const Date &anotherDate) {
        this->year = anotherDate.year;
        this->month = anotherDate.month;
        this->day = anotherDate.day;
        this->hour = anotherDate.hour;
        this->minute = anotherDate.minute;
        this->second = anotherDate.second;
        this->isOurEra = anotherDate.isOurEra;
    }

    Date add(int years, int months, int days, int hours, int minutes, int seconds) {
        int new_second = seconds + second;
        int new_minute = minutes + minute;
        int new_hour = hours + hour;
        int new_day = days + day;
        int new_month = months + month;
        int new_year = years + year;
        int new_era = isOurEra;

        while (new_second >= 60) {
            new_minute++;
            new_second -= 60;
        } while (new_minute >= 60) {
            new_hour++;
            new_minute -= 60;
        } while (new_hour >= 24) {
            new_day++;
            new_hour -= 24;
        } while (new_month > 12) {
            new_year++;
            new_month -= 12;
        }

        while (new_day > daysInMonth(new_year, new_month)) {
            new_month++;
            new_day -= daysInMonth(new_year, new_month);
        }

        Date temp(new_year,
                  new_month,
                  new_day,
                  new_hour,
                  new_minute,
                  new_second,
                  new_era);
        return temp;
    }

    Date subtract(int years, int months, int days, int hours, int minutes, int seconds) {
        int new_second = second - seconds;
        int new_minute = minute - minutes;
        int new_hour = hour - hours;
        int new_day = day - days;
        int new_month = month - months;
        int new_year = year - years;
        int new_era = isOurEra;

        while(new_second < 0) {
            new_hour--;
            new_second += 60;
        } while(new_minute < 0) {
            new_hour--;
            new_minute += 60;
        } while(new_hour < 0) {
            new_day--;
            new_hour += 24;
        } while(new_day < 0) {
            new_month--;
            new_day += daysInMonth(new_year, new_month);
        } while(new_month < 0) {
            new_year--;
            new_month += 12;
        }

        if (new_year < 0){
            new_year = abs(new_year);
            new_era = false;
        } else if (new_year == 0) {
            new_year = 1;
        }

        if (new_day == 0) new_day = 1;
        if (new_month == 0) new_month = 1;

        Date temp(new_year,
                  new_month,
                  new_day,
                  new_hour,
                  new_minute,
                  new_second,
                  new_era);
        return temp;
    }


    Date &operator=(const Date &anotherDate){
        this->year = anotherDate.year;
        this->month = anotherDate.month;
        this->day = anotherDate.day;
        this->hour = anotherDate.hour;
        this->minute = anotherDate.minute;
        this->second = anotherDate.second;
        this->isOurEra = anotherDate.isOurEra;

        return *this;
    }

    bool operator==(const Date &anotherDate) const {
        return (this->year == anotherDate.year &&
                this->month == anotherDate.month &&
                this->day == anotherDate.day &&
                this->hour == anotherDate.hour &&
                this->minute == anotherDate.minute &&
                this->second == anotherDate.second &&
                this->isOurEra == anotherDate.isOurEra);
    }

    bool operator<(const Date &anotherDate) const {
        if(this->year < anotherDate.year){
            return true;
        } else if (this->year > anotherDate.year){
            return false;
        }

        if(this->month < anotherDate.month){
            return true;
        } else if (this->month > anotherDate.month){
            return false;
        }

        if(this->day < anotherDate.day){
            return true;
        } else if (this->day > anotherDate.day){
            return false;
        }

        if(this->hour < anotherDate.hour){
            return true;
        } else if (this->day > anotherDate.day){
            return false;
        }

        if(this->minute < anotherDate.minute){
            return true;
        } else if (this->minute > anotherDate.minute){
            return false;
        }

        return this->second < anotherDate.second;
    }

    bool operator>(const Date &anotherDate) const {
        return !(*this < anotherDate);
    }

    Date &operator+=(const Date &anotherDate) {
        *this = this->add(anotherDate.year,
                                anotherDate.month,
                                anotherDate.day,
                                anotherDate.hour,
                                anotherDate.minute,
                                anotherDate.second);
        return *this;
    }

    Date operator+(const Date &anotherDate) {
        Date result;
        result = *this;
        result = result.add(anotherDate.year,
                                  anotherDate.month,
                                  anotherDate.day,
                                  anotherDate.hour,
                                  anotherDate.minute,
                                  anotherDate.second);
        return result;
    }

    Date &operator-=(const Date &anotherDate) {
        *this = this->subtract(anotherDate.year,
                                  anotherDate.month,
                                  anotherDate.day,
                                  anotherDate.hour,
                                  anotherDate.minute,
                                  anotherDate.second);
        return *this;
    }

    Date operator-(const Date &anotherDate) {
        Date result;
        result = *this;
        result = result.subtract(anotherDate.year,
                            anotherDate.month,
                            anotherDate.day,
                            anotherDate.hour,
                            anotherDate.minute,
                            anotherDate.second);
        return result;
    }

    friend ostream& operator<<(ostream& os, const Date& dt) {
        os << dt.day << "-" << dt.month << "-" << dt.year << " ";
        os << dt.hour << ":" << dt.minute << ":" << dt.second << " ";
        os << (dt.isOurEra ? "AD" : "BC");
        return os;
    }
};

int main() {

    Date d1;
    cout << "d1: " <<  d1 << endl;

    Date d2(2060, 1, 1, 15, 12, 43, true);
    cout << "d2: " <<  d2 << endl;

    Date d3(40, 1, 15, 4, 27, 1, true);
    cout << "d3: " <<  d3 << endl;

    Date d4 = d2 - d3;
    cout << "d4 = d2 - d3: " << d4 << endl;

    Date d5 = d2 + d3;
    cout << "d5 = d2 + d3: " << d5 << endl;

    Date d6 = d4 - d1;
    cout << "d6 = d4 - d1: " << d6 << endl;




    return 0;
};
