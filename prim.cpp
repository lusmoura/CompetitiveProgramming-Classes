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

int n;
vector<edge> adjlist[10000];
vector<edge> tree;

int prim() {
    auto pq = priority_queue<edge>();
    auto vis = vector<bool>(n, false);

    // start on node 0
    for (auto e : adjlist[0]) {
        pq.push(e);
    }
    vis[0] = true;

    int sum = 0;
    while (not pq.empty()) {
        auto e = pq.top();
        pq.pop();
        if (not vis[e.v]) {
            tree.push_back(e);
            sum += e.weight;

            for (auto f : adjlist[e.v]) {
                pq.push(f);
            }
        }
    }

    return sum;
}

int main() {
    return 0;
}
