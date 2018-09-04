#include<iostream>
using namespace std;

int main() {
    int N, arr[501], num = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    for(int i = 0; i < N - 1; i++)
        for(int j = i + 1; j < N; j++)
            if(arr[i] + arr[j] == 0)
                num++;
    cout << num;
}
