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

int n, a, b;
char str[maxn];

int main() {
    n = read(); a = read(); b = read();
    scanf("%s", str);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a == 0 && b == 0) break;
        if(i == 0 && str[i] == '.') {
            if(a >= b && a > 0) {
                ans++;
                a--;
                str[i] = 'a';
            }
            else if(b > a && b > 0) {
                ans++;
                b--;
                str[i] = 'b';
            }
        }
        if(str[i] == '.') {
            if(str[i-1] == '*') {
                if(a >= b && a > 0) {
                    str[i] = 'a';
                    ans++;
                    a--;
                }
                else if(b > a && b > 0) {
                    str[i] = 'b';
                    ans++;
                    b--;
                }
            }
            else if(str[i-1] == 'a') {
                if(b > 0) {
                    b--;
                    ans++;
                    str[i] = 'b';
                }
            }
            else if(str[i-1] == 'b') {
                if(a > 0) {
                    a--;
                    ans++;
                    str[i] = 'a';
                }
            }
            else if(str[i-1] == '.') {
                if(a > 0) {
                    str[i] = 'a';
                    a--;
                    ans++;
                }
                else if(b > 0) {
                    str[i] = 'b';
                    b--;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}