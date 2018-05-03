#include<bits/stdc++.h>
using namespace std;
// #define fi first
// #define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define piii pair<pii, int>
#define mem(a,b) memset(a,b,sizeof(a))
#define ull unsigned long long
#define ll long long
#define inf 0x3f3f3f3f

const int maxn = 200000+5;
const ll maxd = 2e14+5;
const double eps = 1e-6;
const double pi = 3.141592653589793238462643385;
const int mod = 1e9;

template <class T>
void show(T a[], int len) {
    for(int i = 1; i <= len; i ++) cout << a[i] << " "; cout << endl;
}

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; ll a, b; cin >> a >> b;
    map<ll, ll> vis;
    map<pii, int> sim;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int x, vx, vy;
        scanf("%d %d %d", &x, &vx, &vy);
        /// x 相遇
        /// t*vx1 + x1 = t * vx2 + x2
        /// y 相遇
        /// t * vy1 + (ax1 + b) = t * vy2 + (ax2 + b)
        /// 两个t相等，即相遇
        /// x2 - x1    ax2 - ax1
        /// ------- = -----------
        /// vx1-vx2    vy1 - vy2
        /// 即
        /// a*x1 - x1 = a*x2 - x2
        /// 再去掉速度平行的点
        ans += vis[a*vx-vy] - sim[{vx,vy}];
        vis[a*vx-vy]++;
        sim[{vx,vy}]++;
    }
    cout << 2*ans << endl;
    return 0;
}
