#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    string s;
    cin >> s;
    auto len_s = static_cast<int>(s.length());
    vector<int> cnt(len_s,1);
    rep(i,len_s){
        if(i+2<len_s&&s[i]=='R'&&s[i+1]=='R'){
            cnt[i+2]+=cnt[i];
            cnt[i]=0;
        }
    }
    rep(i,len_s){
        auto ri=len_s-1-i;
        if(ri-2>=0&&s[ri]=='L'&&s[ri-1]=='L'){
            cnt[ri-2]+=cnt[ri];
            cnt[ri]=0;
        }
    }
    rep(i,len_s){
        cout << cnt[i] << ((i==len_s-1)?"":" ");
    }
    cout << endl;
    return 0;
}