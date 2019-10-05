#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
vector<pair<char,int>> compress(const string &s){
    vector<pair<char,int>> ret;
    char c=s[0];
    int cnt=1;
    rep(i,1,s.size()){
        if(c==s[i])++cnt;
        else{
            ret.push_back({c,cnt});
            c=s[i];
            cnt=1;
        }
    }
    ret.push_back({c,cnt});
    return ret;
}
int main(){
    string s;
    ll k;
    cin >> s >> k;
    auto cmp=compress(s);
    if(cmp.size()==1){
        cout << (k*s.size())/2 << endl;
    }else if(s[0]==s[s.size()-1]){
        ll a=(cmp[0].second+cmp[cmp.size()-1].second)/2-cmp[0].second/2-cmp[cmp.size()-1].second/2;
        for(const auto &p:cmp){
            a+=p.second/2;
        }
        ll b=0;
        for(const auto &p:cmp){
            b+=p.second/2;
        }
        cout << (k-1)*a+b << endl;
    }else{
        ll a=0;
        for(const auto &p:cmp){
            a+=p.second/2;
        }
        cout << k*a << endl;
    }
    return 0;
}