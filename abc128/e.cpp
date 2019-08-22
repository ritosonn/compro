#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    int n,q;
    cin >> n >> q;
    vector<array<ll,3>> events(n);
    rep(i,n){
        ll s,t,x;
        cin >> s >> t >> x;
        events.push_back({s-x,1,x});
        events.push_back({t-x,-1,x});
    }
    sort(events.begin(),events.end(),[](array<ll,3> a,array<ll,3> b){return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]);});
    set<ll> stop_coord;
    rep(i,q){
        ll d;
        cin >> d;
        while(!events.empty() && (*events.rbegin())[0]<=d){
            if( (*events.rbegin())[1] == 1 )stop_coord.emplace((*events.rbegin())[2]);
            else stop_coord.erase((*events.rbegin())[2]);
            events.pop_back();
        }
        if(stop_coord.empty())cout << "-1" << endl;
        else cout << *stop_coord.begin() << endl;
    }
    return 0;
}