#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    int side_unhappy=(s[0]=='L'?1:0)+(s[n-1]=='R'?1:0);
    int middle_unhappy=0;
    rep2(i,1,n){
        if(s[i-1]=='R'&&s[i]=='L')middle_unhappy++;
    }
    while(k>0){
        if(middle_unhappy>1||(middle_unhappy==1&&side_unhappy>0)){
            --middle_unhappy;
            --k;
        }else if(middle_unhappy==1&&side_unhappy==0){
            --middle_unhappy;
            ++side_unhappy;
            --k;
        }else if(side_unhappy>1){
            --side_unhappy;
            --k;
        }else{
            break;
        }
    }
    cout << n-middle_unhappy*2-side_unhappy << endl;
    return 0;
}