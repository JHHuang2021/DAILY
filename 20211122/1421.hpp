// src.hpp 框架代码
//代码中的所有内容均可修改
#include <iostream>
#include <algorithm>
#include "base.hpp"

// !!!如果要新增include文件请举手询问助教
using namespace std;

struct date {
    int year = 0, month = 0, day = 0;

    date() = default;

    date(int y, int m, int d) : year(y), month(m), day(d) {}

    friend istream &operator>>(istream &input, date &d) {
        string str[3];
        for (int i = 0; i <= 2; i++)
            input >> str[i];
        d.year = atoi(str[0].c_str());
        d.month = atoi(str[1].c_str());
        d.day = atoi(str[2].c_str());
        return input;
    }

    int operator-(const date &rhs) const {
        return (this->year - rhs.year) * 360 + (this->month - rhs.month) * 30 + this->day - rhs.day;
    }

    bool operator<(const date &rhs) const {
        if (year < rhs.year)
            return true;
        if (rhs.year < year)
            return false;
        if (month < rhs.month)
            return true;
        if (rhs.month < month)
            return false;
        return day < rhs.day;
    }

    bool operator==(const date &rhs) const {
        return year == rhs.year &&
               month == rhs.month &&
               day == rhs.day;
    }
};

class mail : public object {
protected:
    string postmark;
    date send_date;
    date arrive_date;

public:
    mail() = default;

    mail(string _contain_, string _postmark_, date send_d, date arrive_d) : object(_contain_) {
        postmark = _postmark_;
        send_date = send_d;
        arrive_date = arrive_d;
    }

    virtual string send_status(int y, int m, int d) {
        return "not send";
    }

    virtual string type() {
        return "no type";
    }

    virtual void print() {
        object::print();
        cout << "[mail] postmark: " << postmark << endl;
    }

    virtual void copy(object *o) {
        mail &m = *dynamic_cast<mail *>(o);
        contain = m.contain;
        postmark = m.postmark;
        send_date = m.send_date;
        arrive_date = m.arrive_date;
    }

    virtual ~mail() {}

};

class air_mail : public mail {
protected:
    string airlines;
    date take_off_date;
    date land_date;

public:
    air_mail() = default;

    air_mail(string _contain_, string _postmark_, date send_d, date arrive_d, date take_off, date land, string _airline) : mail(
            _contain_, _postmark_, send_d, arrive_d) {
        take_off_date = take_off;
        land_date = land;
        airlines = _airline;
    }

    virtual string send_status(int y, int m, int d) {
        date ask_date(y, m, d);
        if (ask_date < send_date)
            return "mail not send";
        else if (ask_date < take_off_date)
            return "wait in airport";
        else if (ask_date < land_date)
            return "in flight";
        else if (ask_date < arrive_date)
            return "already land";
        else
            return "already arrive";
    }

    virtual string type() {
        return "air";
    }

    virtual void print() {
        mail::print();
        cout << "[air] airlines: " << airlines << endl;
    }

    virtual void copy(object *o) {
        air_mail &m = *dynamic_cast<air_mail *>(o);
        contain = m.contain;
        postmark = m.postmark;
        send_date = m.send_date;
        arrive_date = m.arrive_date;
        take_off_date = m.take_off_date;
        land_date = m.land_date;
        airlines = m.airlines;
    }

    virtual ~air_mail() {}
};

class train_mail : public mail {
protected:
    string *station_name;
    date *station_time;
    int len;

public:
    train_mail() {};

    train_mail(const string &contain, const string &postmark, const date &sendD, const date &arriveD, string *stationName,
               date *stationTime, int len) : mail(contain, postmark, sendD, arriveD), len(len) {
        station_time = new date[len];
        station_name = new string[len];
        for (int i = 0; i < len; i++) {
            this->station_time[i] = stationTime[i];
            this->station_name[i] = stationName[i];
        }
    }

    virtual string send_status(int y, int m, int d) {
        date ask_date(y, m, d);
        if (ask_date < send_date)
            return "mail not send";
//        else if (!(ask_date < arrive_date))
//            return "already arrive";
        else if (ask_date < station_time[0])
            return "wait in departure station";
        else {
            for (int i = 0; i < len; i++) {
                if (ask_date < station_time[i])
                    return "between " + station_name[i - 1] + " and " + station_name[i];
                if (ask_date == station_time[i] && !(ask_date == arrive_date))
                    return "at " + station_name[i];
            }
            if (ask_date < arrive_date)
                return "wait in terminus station";
            else if (!(ask_date < arrive_date))
                return "already arrive";
        }
    }

    virtual string type() {
        return "train";
    }

    virtual void print() {
        mail::print();
        cout << "[train] station_num: " << len << endl;
    }

    virtual void copy(object *o) {
        train_mail &m = *dynamic_cast<train_mail *>(o);
        if (dynamic_cast<train_mail *>(o) == this) return;
        contain = m.contain;
        postmark = m.postmark;
        send_date = m.send_date;
        arrive_date = m.arrive_date;
//        delete[]station_time;
//        delete[]station_name;
        len = m.len;
        station_time = new date[len];
        station_name = new string[len];
        for (int i = 0; i < len; ++i) {
            station_time[i] = m.station_time[i];
            station_name[i] = m.station_name[i];
        }
    }

    virtual ~train_mail() {
        delete[]station_name;
        delete[]station_time;
    };
};

class car_mail : public mail {
protected:
    long long total_mile;
    string driver;

public:
    car_mail() = default;

    car_mail(const string &contain, const string &postmark, const date &sendD, const date &arriveD, long long totalMile,
             const string &driver) : mail(contain, postmark, sendD, arriveD), total_mile(totalMile), driver(driver) {}

    virtual string send_status(int y, int m, int d) {
        date ask_date(y, m, d);
        if (ask_date < send_date)
            return "mail not send";
        else if (ask_date < arrive_date) {
            double current_mile = static_cast<double> (ask_date - send_date) / static_cast<double> (arrive_date - send_date) *
                                  static_cast<double> (total_mile);
            return "at " + to_string(current_mile);
        } else
            return "already arrive";
    }

    virtual string type() {
        return "car";
    }

    virtual void print() {
        mail::print();
        cout << "[car] driver_name: " + driver << endl;
    }

    virtual void copy(object *o) {
        car_mail &m = *dynamic_cast<car_mail *>(o);
        contain = m.contain;
        postmark = m.postmark;
        send_date = m.send_date;
        arrive_date = m.arrive_date;
        total_mile = m.total_mile;
        driver = m.driver;
    }

    virtual ~car_mail() {}
};


void obj_swap(object *&x, object *&y) {
    auto tmp = x;
    x = y;
    y = tmp;
}