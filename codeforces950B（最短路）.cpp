#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f

const int maxn = 106;

int n, road;
int u, v, w, st, ed;
char a[maxn];

struct qnode {
    int v, c;
    qnode(int tempv = 0, int tempc = 0) : v(tempv), c(tempc) {}
    bool operator < (const qnode &r) const {
        return c > r.c;
    }
};

struct Edge{
    int start, cost;
    Edge(int tempstart = 0, int tempcost = 0) : start(tempstart), cost(tempcost){}

};
vector <Edge> E[250];
bool vis[250];
int dist[250];

void dij(int start) {
    mem(vis, 0);
    for(int i = 0; i <= n; i++) dist[i] = INF ;
    priority_queue <qnode> pq ;
    while(!pq.empty())  pq.pop(); // reset
    dist[start] = 0;
    pq.push(qnode(start, 0));
    qnode tmp;
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < E[u].size(); i++) {
            int v = E[u][i].start;
            int cost = E[u][i].cost;
            if(!vis[v]) {
                dist[v] = min(dist[v], dist[u]+cost);
                pq.push(qnode(v, dist[v]));
            }
        }
    }
}

void addedge(int u, int v, int w) {
    E[u].push_back(Edge(v, w));
    E[v].push_back(Edge(u, w));
}

int main() {
    while(cin >> n) {
        memset(a, '\0', sizeof(a));
        for(int i = 0; i <= n; ++ i) E[i].clear();
        getchar();
        for(int i = 1;i <= n;i++) scanf("%c", &a[i]);
        getchar();
        for(int k = 0;k < n;k++) {
            E[k].push_back(Edge(k+1, 1));
        }
        int i;
        for(i = 1;i <= n/2;i++) {
            int j, flag=1;
            for(j = 1;j <= i;j++) {
                if(a[j] != a[j+i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                E[i].push_back(Edge(2*i, 1));
            }
        }
        dij(0);
        cout << dist[n] << endl;
    }
    return 0;
}