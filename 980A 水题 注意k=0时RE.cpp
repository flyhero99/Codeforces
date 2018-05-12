#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100+5;

char s[maxn];

int main() {
	cin >> s;
	int len = strlen(s);
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] == '-') cnt1++;
		else cnt2++;
	}
	if(cnt2 == 0) cout << "YES" << endl;
	else if(cnt1%cnt2 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}