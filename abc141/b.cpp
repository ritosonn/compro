#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    string s;
    cin >> s;
    bool ans=true;
    loop(i,s.length()){
        if((i%2==0&&s[i]=='L')||(i%2==1&&s[i]=='R'))ans=false;
    }
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}