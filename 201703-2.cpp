#include<iostream>
using namespace std;

int tract(int pos[], int n, int num) {
    for(int i = 1; i <= n; i++)
        if(pos[i] == num)
            return i;
    return 0;
}

int main() {
    int n, m;
    int pos[1000] = {0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        pos[i] = i;
    for(int i = 0; i < m; i++) {
        int p, q, fron, tail;
        cin >> p >> q;
        if(q > 0) {
            fron = tract(pos, n, p);
            tail = fron + q;
            int temp = pos[fron];
            for(int j = fron; j < tail; j++)
                pos[j] = pos[j + 1];
            pos[tail] = temp;
        }
        else {
            tail = tract(pos, n, p);
            fron = tail + q;
            int temp = pos[tail];
            for(int j = tail; j > fron; j--)
                pos[j] = pos[j - 1];
            pos[fron] = temp;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << pos[i] << " ";
    cout << endl;
    return 0;
}
