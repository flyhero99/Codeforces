#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
// #define fi first
// #define se second
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define il inline
#define lowbit(x) x&-x

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

int n, q;
ll a[maxn], suma[maxn];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> q) {
        mem(suma, 0); suma[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            suma[i] = suma[i-1] + a[i];
        }
        ll qry = 0, x;
        for(int i = 1; i <= q; i++) {
            cin >> x; qry += x;
            if(qry >= maxd) qry = maxd;
            if(qry >= suma[n]) {
                qry = 0;
                cout << n << endl;
                continue;
            }
            int alive = lower_bound(suma+1, suma+n+1, qry) - suma;
            ll ans;
            if(qry == suma[alive]) cout << n-alive << endl;
            else cout << n-alive+1 << endl;
        }
    }
    return 0;
}