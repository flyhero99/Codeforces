#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 200005;

template<class T>
void show(T a[], int len) {
    for(int i = 0; i <= len; i++)
        cout << a[i] << " ";
    cout << endl;
}

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int b[15];
ll qw[15];
ll n, d;
int cnt, p = 100;

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    qw[0] = 1;
    for(int i = 1; i <= 10; i++) {
        qw[i] = qw[i-1]*10;
    }
    n = read();
    d = n; cnt = 0;
    while(d) {
        b[cnt] = d%10;
        d /= 10;
        cnt++;
    }
    int up = pow(2, cnt);
    for(int i = 1; i < up; i++) {
        int ans = 0;
        long long sum = 0;
        for(int j = 0; j < cnt; j++) {
            if(1 & (i>>j)) { // 枚举为1的位数
                sum += b[j]*qw[ans];
                ans++;
            }
        }
        ll sb = sqrt(sum);
        if(sb*sb == sum && sum >= qw[ans-1]) { // 取删除位数最小
            p = min(p, cnt-ans);
        }
    }
    if(p == 100) cout << -1 << endl;
    else cout << p << endl;
    return 0;
}