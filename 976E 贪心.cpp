#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define fi first
#define se second
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

ll n, a, b;

struct node {
    ll h, d, m;

    bool operator < (const node &k) const {
        return k.m < m;
    }
}arr[maxn];

// 翻a次倍，等攻b次
// 原始伤害s1，b次等攻增加伤害s2，按hp-dmg大的排序，a次翻倍肯定是翻同一个怪最赚（贪心），
// 对于前b个怪，判断翻每个怪本身是不是最大，对于b+1后面的怪，判断翻它和翻第b个哪个更赚（因为原始差值最小的是第b项）

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> a >> b) {
        b = min(b, n);
        ll s1 = 0LL, s2 = 0LL, ans = 0LL;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i].h >> arr[i].d;
            arr[i].m = max(0LL, arr[i].h-arr[i].d);
            s1 += arr[i].d; // 原始伤害
        }
        if(b == 0) {
            cout << s1 << endl;
            continue;
        }
        sort(arr+1, arr+n+1);
        for(int i = 1; i <= b; i++) {
            s2 += arr[i].m; // delta(d)
        }
        for(int i = 1; i <= b; i++) {
            ans = max(ans, s2 - arr[i].m + (arr[i].h<<a)-arr[i].d);
        }
        for(int i = b+1; i <= n; i++) {
            ans = max(ans, s2 - arr[b].m + (arr[i].h<<a)-arr[i].d);
        }
        cout << s1+ans << endl;
    }
    return 0;
}