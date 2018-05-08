#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200000+5;

// dp数组可以用map开

map<int, int> dp;
int a[maxn];

vector<int> res;

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 0, r = 0;
	for(int i = 0; i < n; i++) {
		int x = a[i];
		dp[x] = dp[x-1]+1;
		if(ans < dp[x]) {
			ans = dp[x];
			r = x;
		}
	}
	for(int i = n-1; i >= 0; i--) {
		if(a[i] == r) {
			res.push_back(i);
			r--;
		}
	}
	printf("%d\n", ans);
	for(int i = res.size()-1; i >= 0; i--) {
		printf("%d ", res[i]+1);
	}
	printf("\n");
	return 0;
}