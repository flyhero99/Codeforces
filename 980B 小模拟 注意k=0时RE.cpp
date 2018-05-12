#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100+5;

int n, k;
string a[4];

int main() {
	cin >> n >> k;
	puts("YES");
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < n; j++) a[i].push_back('.');
	}
	if(k % 2 == 0) {
		int r = 1, c = 1;
		while(1) {
			if(k <= 0) break;
			a[r][c] = '#';
			r++; k--;
			if(k <= 0) break;
			if(r >= 3) {
				r = 1;
				c++;
			}
		}
	}
	else {
		int l = n/2, r = n/2, c = 1;
		while(1) {
			if(k <= 0) break;
			a[c][l] = a[c][r] = '#';
			if(l == r) k--;
			else k -= 2;
			if(k <= 0) break;
			l--, r++;
			if(l <= 0) break;
		}
		l = n/2-1, r = n/2+1, c = 2;
		while(1) {
			if(k <= 0) break;
			a[c][l] = a[c][r] = '#';
			k -= 2;
			l--; r++;
		}
	}
	for(int i = 0; i < 4; i++) cout << a[i] << endl;
	return 0;
}