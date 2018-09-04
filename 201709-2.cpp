#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n, k, mintime = 1000000, pos1 = 0, pos2 = 0, num = 0;
    int time[1000], order[1000], vacancy[1000];
    for(int i = 1; i <= n; i++) {
        order[i] = i;
        time[i] = 0;
    }
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        int m, start, length;
        cin >> m >> start >> length;
        time[m] = start + length;
    }
    for(int i = 1, j = 0; i <= n; i++) {
        if(time[i] != 0)
            vacancy[j++] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            if(time[j] != 0 && time[j] < mintime) {
                mintime = time[j];
                pos1 = j;
            }
        pos2 = vacancy[num++];
        order[pos1] = pos2;
        order[pos2] = pos1;
        mintime = 1000000;
        time[pos1] = 0;
        pos1 = 0;
    }
    for(int i = 1; i <= n; i++)
        cout << order[i] << " ";
    cout << endl;
    return 0;
}
