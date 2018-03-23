#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 106;

int n;
char a[maxn];


int main() {
    while(cin >> n) {
        scanf("%s", a);
        int len1 = strlen(a);
        int ans = strlen(a);
        for(int i = 0;i < len1-1;i++) {
            if(a[i] == 'U') {
                if(a[i+1] == 'R') {
                    ans--;
                    i++;
                }
            }
            else if(a[i] == 'R') {
                if(a[i+1] == 'U') {
                    ans--;
                    i++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}