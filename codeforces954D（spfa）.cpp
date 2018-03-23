// 单源最短路 SPFA
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define  MAXN 20010  // 最大顶点数

using namespace std;

bool vis[MAXN]; // 是否在队列
int cnt[MAXN];  // 每个顶点的入队列次数，用于判定是否存在负环回路
int dist[MAXN];

struct Edge {
    int v;
    int cost;

    Edge(int v, int cost) {
        this->v = v;
        this->cost = cost;
    }
};

vector <Edge> ver[MAXN];

void addEdge(int u, int v, int w) {
    ver[u].push_back(Edge(v, w));
}

bool SPFA(int start, int n) {
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    queue<int> que;

    vis[start] = true;
    que.push(start);
    cnt[start] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int i = 0; i < ver[u].size(); i++) {
            int v = ver[u][i].v;
            int t_cost = dist[u] + ver[u][i].cost;
            if (dist[v] > t_cost) {
                dist[v] = t_cost;
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                    if (++cnt[v] > n) // 判定负环回路
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m; // n个顶点，m条边
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    SPFA(1, n);
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << endl;
    }
    return 0;
}