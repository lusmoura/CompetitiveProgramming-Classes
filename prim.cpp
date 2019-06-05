#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v;
    int weight;

    bool operator<(const edge & that) const {
        // invertido pq a priority_queue por padrão ordena do maior pro menor
        // e nós queremos o contrário
        return this->weight > that.weight;
    }
};

int n, m;
vector<edge> adjlist[10000];
vector<edge> mst;

int prim() {
    auto pq = priority_queue<edge>();
    auto vis = vector<bool>(n, false);

    // start on node 0
    for (auto e : adjlist[1]) {
        pq.push(e);
        cout << "pushed " << e.u << " -> " << e.u << " (" << e.weight << ") " << endl;
    }
    vis[0] = true;

    int sum = 0;
    while (not pq.empty()) {
        auto e = pq.top();
        pq.pop();
        if (not vis[e.v]) {
            vis[e.v] = true;
            mst.push_back(e);
            sum += e.weight;

            for (auto f : adjlist[e.v]) {
                pq.push(f);
            }
        }
    }

    return sum;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cout << u << v << w << endl;
        adjlist[u].push_back({u,v,w});
    }

    auto total = prim();

    cout << "Total weight: " << total << endl;

    cout << "MST: " << endl;
    for (auto e : mst) {
        cout << e.u << " -> " << e.v << " (" << e.weight << ")" << endl;
    }

    return 0;
}
