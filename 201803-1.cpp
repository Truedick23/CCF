#include<iostream>
using namespace std;

int main() {
    int present = 0, former = 1, score = 0, times = 0;
    cin >> present;
    while(present) {
        if(present == 2) {
            if(former != 1)
                times++;
            if(former == 1)
                times = 1;
            score += times * 2;
        }
        if(present == 1) {
            times = 0;
            score++;
        }
        former = present;
        cin >> present;
    }
    cout << score;
}
