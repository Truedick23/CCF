#include<iostream>
#include<vector>
using namespace std;

#define RIGHT 1
#define LEFT -1

struct Ball {
    int pos;
    int direct;
    Ball(int p = 0, int d = RIGHT) {
        pos = p;
        direct = d;
    }
};

int main() {
    vector<Ball> balls;
    int n, L, T;
    cin >> n >> L >> T;
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        balls.push_back(Ball(p));
    }
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < n; i++) {
            int flag = 0;
            if(balls[i].pos == L && balls[i].direct == RIGHT || balls[i].pos == 0 && balls[i].direct == LEFT) {
                balls[i].direct = -balls[i].direct;
                balls[i].pos += balls[i].direct;
                continue;
            }
            for(int j = 0; j < n; j++) {
                if(i != j && balls[i].pos == balls[j].pos && balls[i].direct + balls[j].direct == 0) {
                    balls[i].direct = -balls[i].direct;
                    balls[j].direct = -balls[j].direct;
                    break;
                }
            }
            if(!flag)
                balls[i].pos += balls[i].direct;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        cout << balls[i].pos << " ";
    }
    cout << balls[n-1].pos << endl;
}
