#include<iostream>
using namespace std;

int main() {
    int m, n1, n2, n;
    cin >> m;
    n1 = m / 50;
    n2 = (m - n1 * 50) / 30;
    n = (m - n1 * 50 - n2 * 30) / 10 + n1 * 7 + n2 * 4;
    cout << n << endl;
    return 0;
}
