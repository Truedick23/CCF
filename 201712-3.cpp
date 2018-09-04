//#include "stdafx.h"
#include<iostream>
#include<string>
#include<time.h>
#include<sstream>
#include<set>
#include<vector>
#include<algorithm>
#include<ctype.h>
#define MIN 0
#define HOUR 1
#define DAY 2
#define MON 3
#define WEEK 4
using namespace std;

string Mon[13] = {"ZERO", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "AUG", "SEP", "OCT", "NOV", "DEC"};
string NMon[13] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
string Week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
string NWeek[7] = {"0", "1", "2", "3", "4", "5", "6"};

struct Out {
    unsigned long long time;
    int NIns;
}*pOut;

vector<struct Out> Outs;

void Eng2Num(string &res) {
    int pos;
    for(unsigned int i = 0; i < res.length(); i++)
        if(res[i] >= 'a' && res[i] <= 'z')
            res[i] += ('A' - 'a');
    for(int i = 0; i < 13; i++)
        if((pos = res.find(Mon[i])) != -1)
            res.replace(pos, 3, NMon[i]);
    for(int i = 0; i < 7; i++)
        if((pos = res.find(Week[i])) != -1)
            res.replace(pos, 3, NWeek[i]);
    return;
}

void S2Num(string &res, int Code) {
    int pos;
    if((pos = res.find("*")) != -1) {
        switch(Code) {
        case MIN:
            res.replace(pos, pos + 1, "0-59");
            break;
        case HOUR:
            res.replace(pos, pos + 1, "0-23");
            break;
        case WEEK:
            res.replace(pos, pos + 1, "0-6");
            break;
        case DAY:
            res.replace(pos, pos + 1, "1-31");
            break;
        case MON:
            res.replace(pos, pos + 1, "1-12");
            break;
        default:
            break;
        }
    }
}

void R2Num(string &res, set<unsigned long long> &U) {
    unsigned int pos;
    int _begin, _end;
    int n1, n2;
    while((pos = res.find("-")) != -1) {
        if(pos > 1 && isdigit(res[pos - 2]))
            _begin = pos - 2;
        else
            _begin = pos - 1;
        if(pos < res.length() - 1 && isdigit(res[pos + 2]))
            _end = pos + 2;
        else
            _end = pos + 1;
        stringstream ss;
        ss << res.substr(_begin, pos - _begin);
        ss >> n1;
        ss.clear();
        ss << res.substr(pos + 1, _end - pos);
        ss >> n2;
        res.erase(_begin, _end - _begin + 1);
        for(int i = n1; i <= n2; i++)
            U.insert(i);
    }
}

void T2Num(string &res, set<unsigned long long> &U) {
    if(res == "")   return;
    int pos;
    int n;
    while((pos = res.find(",")) != -1) {
        stringstream ss;
        ss << res.substr(0, pos);
        ss >> n;
        U.insert(n);
        res.erase(0, pos + 1);
    }
    stringstream ss;
    ss << res;
    ss >> n;
    U.insert(n);
}

bool sort_by_time(const struct Out &A, const struct Out &B) {
    if(A.time < B.time)
        return true;
    else if(A.time == B.time && A.NIns < B.NIns)
        return true;
    else
        return false;
}

int main() {
   int n;
   cin >> n;
   string _begin, _end;
   cin >> _begin;
   cin >> _end;
   int year1, year2;
   stringstream ss;
   ss << _begin.substr(0, 4);
   ss >> year1;
   ss.clear();
   ss << _end.substr(0, 4);
   ss >> year2;
   unsigned long long Nbegin, Nend;
   ss.clear();
   ss << _begin;
   ss >> Nbegin;
   ss.clear();
   ss << _end;
   ss >> Nend;
   vector<string> Ins;
   for(int i = 0; i < n; i++) {
        string minute, hour, day, mon, week;
        cin >> minute >> hour >> day >> mon >> week;
        string ins;
        cin >> ins;
        Ins.push_back(ins);
        Eng2Num(mon); Eng2Num(week);
        S2Num(minute, MIN); S2Num(hour, HOUR); S2Num(day, DAY); S2Num(mon, MON); S2Num(week, WEEK);

        set<unsigned long long> Smin; set<unsigned long long> Shour; set<unsigned long long>Sday; set<unsigned long long>Smon; set<unsigned long long>Sweek;
        R2Num(minute, Smin); R2Num(hour, Shour); R2Num(day, Sday); R2Num(mon, Smon); R2Num(week, Sweek);
		T2Num(minute, Smin); T2Num(hour, Shour); T2Num(day, Sday); T2Num(mon, Smon); T2Num(week, Sweek);

        set<unsigned long long>::iterator Imin; set<unsigned long long>::iterator Ihour; set<unsigned long long>::iterator Iday; set<unsigned long long>::iterator Iweek; set<unsigned long long>::iterator Imon;
        for(unsigned long long y = year1; y <= year2; y++) {
            unsigned long long y1;
            for(Imon = Smon.begin(); Imon != Smon.end(); Imon++) {
                unsigned long long m = *Imon;
                if(m == 1 || m == 2) {
                    m += 12;
                    y1 = y - 1;
                }
                else
                    y1 = y;
                for(Iday = Sday.begin(); Iday != Sday.end(); Iday++) {
                    if (*Iday > 30 && (*Imon == 2 || *Imon == 4 || *Imon == 6 || *Imon == 9 || *Imon == 11))
						continue;
					if (!((y % 100 != 0 && y % 4 == 0) ||(y % 400 == 0)) && *Iday > 28 && *Imon == 2)
						continue;
					if (((y % 100 != 0 && y % 4 == 0) ||(y % 400 == 0)) && y % 4 == 0 && *Iday > 29 && *Imon == 2)
                        continue;
                    for (Iweek = Sweek.begin(); Iweek != Sweek.end(); Iweek++) {
						if (*Iweek == (*Iday + 2 * m + 3 * (m + 1) / 5 + y1 + y1 / 4 - y1 / 100 + y1 / 400 + 1) % 7)
							break;
					}
					if (Iweek == Sweek.end())
						continue;
                    for(Ihour = Shour.begin(); Ihour != Shour.end(); Ihour++) {
                        for(Imin = Smin.begin(); Imin != Smin.end(); Imin++) {
                            unsigned long long time = 0;
                            time += *Imin;
                            time += *Ihour * 100;
                            time += *Iday * 10000;
                            time += *Imon * 1000000;
                            time += y * 100000000;
                            if(time < Nbegin || time >= Nend)
                                continue;
                            struct Out out;
                            out.time = time;
                            out.NIns = i;
                            Outs.push_back(out);
                        }
                    }
                }
            }
        }
    }
    sort(Outs.begin(), Outs.end(), sort_by_time);
    vector<Out>::iterator i;
    for(i = Outs.begin(); i < Outs.end(); i++)
        cout << (*i).time << " " << Ins[(*i).NIns] << endl;
    return 0;
}
