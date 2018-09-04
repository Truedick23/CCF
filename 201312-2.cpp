#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
    string oldstr, newstr;
    cin >> oldstr;
    newstr = oldstr.substr(0, 11);
    char match[] = "0123456789X";
    newstr.erase(1, 1); newstr.erase(4, 1);
    int sum = 0, remain;
    for(int i = 0; i < 9; i++) {
        char c;
        if(isdigit(c = newstr.at(i)))
            sum += (c - '0') * (i + 1);
    }
    //cout << sum;
    remain = sum % 11;
    if(oldstr.at(12) == match[remain])
        cout << "Right";
    else
        cout << oldstr.substr(0, 12) + match[remain];
}
