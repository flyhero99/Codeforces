#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define maxn 1010  // 最大顶点数

using namespace std;

struct Edge {
    int v;
    int cost;

    Edge(int v, int cost) {
        this->v = v;
        this->cost = cost;
    }
};

vector<Edge> ver[maxn];
bool vis[maxn]; // 是否在队列
bool bian[maxn][maxn];
int cnt[maxn];  // 每个顶点的入队列次数，用于判定是否存在负环回路
// int dist[maxn];
int n, m, start, ed;

void addEdge(int u, int v, int w) {
    ver[u].push_back(Edge(v, w));
}

bool spfa(int st, int *dist) {
    memset(dist, inf, sizeof(dist));
    dist[st] = 0;
    queue<int> que;

    vis[st] = true;
    que.push(st);
    cnt[st] = 1;
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
    cin >> n >> m >> start >> ed;
        int ans = 0;
        mem(bian, false);
        for(int i = 0;i <= n;i++) ver[i].clear();
        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            bian[u][v] = true;
            bian[v][u] = true;
            addEdge(u, v, 1);
            addEdge(v, u, 1);
        }

        int s[maxn], t[maxn];
        mem(s, inf);
        mem(t, inf);
        spfa(start, s);
        spfa(ed, t);
        // for(int i = 1;i <= n;i++) cout << s[i] << ' ';
        // cout << endl;
        // for(int i = 1;i <= n;i++) cout << t[i] << ' ';
        // cout << endl;
        // for(int i = 1;i <= n;i++) {
        //     for(int j = 1;j <= n;j++) {
        //         cout << bian[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j <= n;j++) {
                if(!bian[i][j]) {
                //     cout << "s[" << i << "]: " << s[i];
                //     cout << " t[" << j << "]: " << t[j] << endl;
                    if(s[i]+t[j]+1 >= s[ed] && s[j]+t[i]+1 >= s[ed]) ans++;
                }
            }
        }
        cout << ans << endl;
    return 0;
}