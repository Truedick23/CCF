#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int len = 0, num, sum = 0, m = 0;
    cin >> num;
    while(num > pow(10, m + 1))
        m++;
    for(int i = m; i >= 1; i--) {
        int digit = num / pow(10, i);
        num -= digit * pow(10, i);
        sum += digit;
    }
    sum += num;
    cout << sum;
    return 0;
}
