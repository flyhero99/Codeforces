/*
 * @Samaritan_infi
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

const int maxn = 200000+5;
char s[maxn];
int a[maxn];
int cnt[maxn][10];
int n;

void show(){
    for(int i = 0 ; i <= n ; i ++ ) {
        for(int j = 0 ; j < 10 ; j ++ ) {
            cout << cnt[i][j] << " " ;
        }cout << endl ;
    }
}

void solve(){
    for (int i = n ; i >= 1 ; i --) {
       for (int j = a[i] - 1 ; j >= (i == 1) ; j --) { ///保证小于原数
           int res = 0 ;
           for (int k = 0 ; k < 10 ; k ++) res += cnt[i - 1][k] ^ (k == j) ;
            
           /// 当第i位为j时，原数的其他位为奇数的数字在第i位之后可以摆下，第i位之前与原数相同保证最大，
           /// 其他位为偶数的数字且在第i位之后可以用9来填充
           if (res <= n - i) {  
               for (int k = 1 ; k < i ; k ++) printf("%d" , a[k]) ;
               printf("%d" , j) ;
               for (int k = 1 ; k <= n - i - res ; k ++) printf("9") ;
               for (int k = 9 ; k >= 0 ; k --) if (cnt[i - 1][k] ^ (k == j)) printf("%d" , k) ;
               puts("") ;
               return ;
           }
       }
    }
    
    for (int i = 1 ; i <= n - 2 ; i ++) printf("9"); puts("") ; 
}


int main(){
    int kase ;
    scanf("%d" , &kase) ;
    while (kase --) {
        scanf("%s" , s + 1) ;
        n = strlen(s + 1) ;
        for (int i = 0; i < 10 ; i ++) cnt[0][i] = 0;

        for (int i = 1 ; i <= n ; i ++) {
            a[i] = s[i] - '0' ;
            for (int k = 0 ; k < 10 ; k ++) cnt[i][k] = cnt[i-1][k] ^ (k == a[i]) ; ///每一行为0-9的奇偶
        }
        
        solve();
    }
    return 0;
}