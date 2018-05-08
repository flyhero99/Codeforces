#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200000+5;

int deg[maxn];
bool vis[maxn];
vector<int> comp;
vector<int> edge[maxn];

void dfs(int v) {
	vis[v] = true;
	comp.push_back(v);
	for(auto to : edge[v]) {
		if(!vis[to]) dfs(to);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		edge[u].push_back(v); edge[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			comp.clear();
			dfs(i);
			bool flag = true;
			for(auto v : comp) flag &= (deg[v] == 2);
			if(flag) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}