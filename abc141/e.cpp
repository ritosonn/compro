#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
char s[5001];
int main(){
    int n;
    cin >> n;
    scanf("%s",s);
    int k_max=0;
    loop(offset,n){
        int k_tmp=0,k_now=0;
        loop(i,n-offset){
            if(s[i]==s[i+offset])++k_now;
            else{
                k_tmp=max(k_tmp,k_now);
                k_now=0;
            }
        }
        k_tmp=max(k_tmp,k_now);
        k_max=min(offset,max(k_max,k_tmp));
    }
    cout << k_max << endl;
    return 0;
}