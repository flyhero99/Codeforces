#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 300005;
const int inf = 0x3f3f3f3f;

int n, m;
int xx[maxn], yy[maxn];

bool ok(int x, int y) {
    for(int i = 1; i <= m; i++) {
        if(x != xx[i] && x != yy[i] && y != xx[i] && y != yy[i]) return false;
    }
    return true;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= m; i++) scanf("%d %d", &xx[i], &yy[i]);
        int z = xx[1];
        int v1, v2;
        for(int i = 1; i <= m; i++) {
            if(z != xx[i] && z != yy[i]) {
                v1 = xx[i];
                v2 = yy[i];
                break;
            }
        }
        if(ok(z, v1) || ok(z, v2)) {
            cout << "YES" << endl;
            continue;
        }
        z = yy[1];
        for(int i = 1; i <= m; i++) {
            if(z != xx[i] && z != yy[i]) {
                v1 = xx[i];
                v2 = yy[i];
                break;
            }
        }
        if(ok(z, v1) || ok(z, v2)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}