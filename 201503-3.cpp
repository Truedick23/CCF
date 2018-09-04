#include<iostream>
using namespace std;
int m[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int leapyear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int i, j, a, b, c, y1, y2, weekd, day, y, days, data;
    cin >> a >> b >> c >> y1 >> y2;
    for(days = 0, i = 1850; i < y1; i++)
        days += 365 + leapyear(i);

    for(i = y1; i <= y2; i++) {
        y = leapyear(i);
        for(data = days, j = 1; j < a; j++)
            data += m[y][j];
        weekd = 1 + data % 7;
        day = (b - 1) * 7 + ((weekd >= c)? (c + 7 - weekd):(c - weekd));
        if(day > m[y][a])
            cout << "none" << endl;
        else {
            cout << i << "/";
            if(a < 10)
                cout << "0";
            cout << a << "/";
            if(day < 10)
                cout << "0";
            cout << day << endl;
        }
        days += 365 + leapyear(i);
    }
    return 0;
}
