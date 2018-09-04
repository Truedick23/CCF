#include<iostream>
#include<algorithm>
using namespace std;

int order[11];

struct Point{
    int x;
    int y;
    Point(int xx, int yy) {
        x = xx; y = yy;
    }
    Point() {
        x = 0; y = 0;
    }
};

struct Window{
    Point startp;
    Point endp;
    Window(int x1, int y1, int x2, int y2) {
        startp = Point(x1, y1);
        endp = Point(x2, y2);
    }
    Window() {
        startp = Point();
        endp = Point();
    }
};

void adjustOrder(int chosen, int order[11], int N) {
    for(int i = chosen; i < N; i++) {
        order[i] = order[i + 1];
    }
    order[N] = chosen;
    for(int i = 1; i <= N; i++) {
        cout << order[i] << " ";
    }
    cout << endl;
}

int getLayer(Point point, Window windows[11], int N) {
    int layer = 0, mark, index;
    for(int i = 1; i <= N; i++) {
        index = order[i];
        /*cout << windows[i].startp.x << " ";
        cout << windows[i].startp.y << " ";
        cout << windows[i].endp.x << " ";
        cout << windows[i].endp.y << endl;*/
        if(windows[index].startp.x <= point.x && windows[index].endp.x >= point.x
           && windows[index].startp.y <= point.x && windows[index].endp.y >= point.y) {
           layer = index;
           mark = i;
        }
    }
    if(layer != 0) {
        for(int i = mark; i <= N; i++)
            order[i] = order[i + 1];
        order[N] = layer;
        /*for(int i = 1; i <= N; i++)
            cout << order[i] << " ";*/
    }
    return layer;
}

int main() {
    int N, M;
    Window windows[11];
    Point points[11];
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        order[i] = i;
    for(int i = 1; i <= N; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        windows[i] = Window(x1, y1, x2, y2);
    }
    for(int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }
    for(int i = 1; i <= M; i++) {
        int layer = getLayer(points[i], windows, N);
        if(layer == 0)
            cout << "IGNORED" << endl;
        else
            cout << layer << endl;
    }
    return 0;
}
