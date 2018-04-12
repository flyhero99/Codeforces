#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
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

/*一看到每次消掉最小的x，然后把下标大的x变成2x，就想要利用优先队列，id小的在队头，
对于每一个数字的优先队列p[x]存储所有值为x数的id，然后优先队列q[x] pop两次，代表合并两个x，
接着在2x那个队列中q[2x] push刚才两个x中的大id，直到q[x].size()<2。然后判断q[2x]的size()，
继续这个操作。直到最后这些数字q[x].size()都小于2。由于数字x较大，我们需要对离散化，
用map存储每一个数字离散化之后的序号，用数组b存map后的序号对应的x，即mp[x]=s，b[s]=x，
x对应的优先队列为q[mp[x]]。当把数字消除更新之后，每个队列中最多只有一个id，
然后每个队列q[i]对应的数字就是b[i]。按照id从小到大，输出size()=1的数字就可以了。
*/

priority_queue<int, vector<int>, greater<int> > q[maxn];
map<ll, int> mmp;
ll a[maxn], b[maxn];
int id[maxn], dd[maxn];
int n;

bool cmp(const int &x, const int &y) {
    return id[x] < id[y];
}

int main() {
    n = read();
    mem(id, inf);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(mmp[a[i]] == 0) {
            ans++;
            mmp[a[i]] = ans;
            b[ans] = a[i];
        }
        q[mmp[a[i]]].push(i);
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) {
        ll s = a[i];
        for(int j = 1; j <= 64; j++) {
            if(q[mmp[s]].size() < 2) break;
            ll s2 = s*2;
            if(mmp[s2] == 0) {
                ans++;
                mmp[s2] = ans;
                b[ans] = s2;
            }
            int d1 = mmp[s], d2 = mmp[s2];
            while(q[d1].size() >= 2) {
                q[d1].pop();
                int d = q[d1].top();
                q[d1].pop();
                q[d2].push(d);
            }
            s = s*2;
        }
    }
    int num = 0;
    for(int i = 1; i <= ans; i++) {
        dd[i] = i;
        if(q[i].size() == 1) {
            num++;
            id[i] = q[i].top();
        }
    }
    sort(dd+1, dd+1+ans, cmp);
    cout << num << endl;
    for(int i = 1; i <= ans; i++) {
        if(id[dd[i]] == inf) break;
        cout << b[dd[i]] << ' ';
    }
    cout << endl;
    return 0;
}