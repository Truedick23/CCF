#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>

using namespace std;
const int N = 5000;

struct trading {
    int orderno;
    char t;
    float price;
    long long quantity;
    bool operator < (const trading &n) const {
        if(t == 's')
            return price > n.price;
        else
            return price < n.price;
    }
};

bool cancelflag[N+1];

int main() {
    trading t;
    priority_queue<trading> sell, buy;
    string strading;
    memset(cancelflag, false, sizeof(cancelflag));

    int no = 0, tno;
    while(cin >> strading) {
        if(strading[0] == 'c') {
            no++;
            cin >> tno;
            cancelflag[tno] = true;
        } else if(strading[0] == 'b' || strading[0] == 's') {
            t.orderno = ++no;
            cin >> t.price >> t.quantity;

            if(strading[0] == 'b') {
                t.t = strading[0];
                buy.push(t);
            } else {
                t.t = strading[0];
                sell.push(t);
            }
        } else
            break;
    }

    t.price = 0;
    t.quantity = 0;
    trading b, s;
    for(;;) {
        while(!buy.empty()) {
            b = buy.top();
            if(cancelflag[b.orderno])
                buy.pop();
            else
                break;
        }
        while(!sell.empty()) {
            s = sell.top();
            if(cancelflag[s.orderno])
                sell.pop();
            else
                break;
        }
        if(buy.empty() || sell.empty())
            break;

        if(b.price >= s.price) {
            t.quantity += min(b.quantity, s.quantity);
            t.price = b.price;

            if(b.quantity == s.quantity) {
                buy.pop();
                sell.pop();
            } else if(b.quantity > s.quantity) {
                b.quantity -= s.quantity;
                buy.pop();
                buy.push(b);
                sell.pop();
            } else {
                buy.pop();
                s.quantity -= b.quantity;
                sell.pop();
                sell.push(s);
            }
        } else
            break;
    }

    printf("%.2f", t.price);
    cout << " " << t.quantity << endl;
    return 0;
}
