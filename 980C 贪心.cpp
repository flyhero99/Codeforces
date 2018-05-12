#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
const int maxm = 300;

int n, k;
int a[maxm];

int main() {
	while(cin >> n >> k) {
		memset(a, -1, sizeof(a));
		while(n--) {
			int x;
			scanf("%d", &x);
			if(a[x] == -1) {
				for(int i = max(0, x-k+1); i <= x; i++) {
					if(a[i] == -1 || a[i] == i) {
						for(int j = i; j <= x; j++) a[j] = i;
						break;
					}
				}
			}
			printf("%d ", a[x]);
		}
		printf("\n");
	}
	return 0;
}
