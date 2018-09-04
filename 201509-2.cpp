#include<iostream>
using namespace std;

bool hasNine(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int main() {
    int year, days, i;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> year >> days;
    if(hasNine(year))
        months[2] = 29;
    for(i = 1; i <= 12; i++) {
        if(months[i] >= days)
            break;
        days -= months[i];
    }
    cout << i << endl << days << endl;
}
