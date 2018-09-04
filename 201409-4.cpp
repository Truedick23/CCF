#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>

#define ROAD 0
#define CUSTOMER 1
#define SHOP 2
#define X 0
#define Y 1
using namespace std;

struct Node {
    int x;
    int y;
    int step;
    Node() {}
    Node(int xx, int yy, int sstep) {
        x = xx;
        y = yy;
        step = sstep;
    }
};

queue<Node> q;
int n;
int buyernum = 0;
int customer[1001][1001];
int visited[1001][1001];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int manip() {
    int ans = 0;
    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        int xx = node.x, yy = node.y;
        for(int i = 0; i < 4; i++) {
            int x = xx + direction[i][X];
            int y = yy + direction[i][Y];
            if(x < 1 || x > n || y < 1 || y > n || visited[x][y])
                continue;
            Node nextN = Node(x, y, 0);
            nextN.step = node.step + 1;
            if(customer[x][y] > 0) {
                ans += nextN.step * customer[x][y];
                buyernum--;
                if(buyernum == 0)
                    return ans;
            }
            visited[x][y] = 1;
            q.push(nextN);
        }
    }
}

int main() {
    int cost = 0, m, k, d;
    cin >> n >> m >> k >> d;

    memset(customer, 0, sizeof(customer));
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        visited[x][y] = 1;
        q.push(Node(x, y, 0));
    }
    for(int i = 0; i < k; i++) {
        int x, y, amount;
        cin >> x >> y >> amount;
        if(customer[x][y] == 0)
            buyernum++;
        customer[x][y] += amount;
    }
    for(int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        visited[x][y] = 1;
    }
    cout << manip() << endl;
    return 0;
}
