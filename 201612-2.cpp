#include<iostream>
using namespace std;

int main() {
    int t, s = 0, roof = 0, i;
    int roofs[9] =
        {0, 3500, 4955, 7655, 11255, 30755, 44755, 61005, 999999};
    int origi[9] =
        {0, 3500, 5000, 8000, 12500, 38500, 58500, 83500, 999999};
    double ra te[9] = {1, 0.97, 0.9, 0.8, 0.75, 0.7, 0.65, 0.55, 0};
    cin >> t;
    for(i = 0; i < 9; i++) {
        if(t <= roofs[i]) {
            break;
        }
    }
    s = origi[i - 1] + (t - roofs[i - 1]) / rate[i - 1];
    cout << s << endl;
}
