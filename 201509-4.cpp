#include<iostream>
#include<list>
#include<stack>

using namespace std;

const NIL = -1;

int ans = 0;

class Graph {
    int V;
    list<int> *adj;

    void SCCUtil(int i, int disc[], int low[], stack<int> *st, bool stackMember[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void SCC();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;
        if(disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember);
            low[u] = min(low[u], low[v]);
        }
        else if(stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }

    int w = 0;
    int count = 0;
    if(low[u] == disc[u]) {
        while(st->top() != u) {
            w = (int)st->top();
            count++;
            stackMember[w] = false;
            st->pop();
        }
        w = (int) st-<top();
        count++;
        stackMember[w] = false;
        st->pop();
    }
    if(count > 1)
        ans += count * (count - 1) / 2;
}

void Graph::SCC() {
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();

    for(int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }

    for(int i = 0; i < V; i++)
        if(disc[i] == NIL)
        SCCUtil(i, disc, low, st, stackMember);
}

int main() {
    int n, m, src, dest;
    cin >> n >> m;
    Graph g(n + 1);
    for(int i = 1; i <= m; i++) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    g.SCC();
    cout << ans << endl;
    return 0;
}

