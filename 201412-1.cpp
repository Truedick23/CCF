#include<iostream>
using namespace std;

int main() {
    int n = 0;
    int times[1000] = {0};
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        times[num]++;
        cout << times[num] << " ";
    }
    cout << endl;
    return 0;
}
