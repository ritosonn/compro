#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using ll3 = array<ll,3>;
ll a[1000],b[1000],c[1000];
int main(){
    int x,y,z;
    std::size_t k;
    cin >> x >> y >> z >> k;
    rep(i,x)cin >> a[i];
    rep(i,y)cin >> b[i];
    rep(i,z)cin >> c[i];
    sort(a,a+x,greater<ll>());
    sort(b,b+y,greater<ll>());
    sort(c,c+z,greater<ll>());
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    rep(ix,x)rep(iy,y)rep(iz,z){
        if(pq.size()<k)pq.push(a[ix]+b[iy]+c[iz]);
        else if(pq.top()<a[ix]+b[iy]+c[iz]){
            pq.pop();
            pq.push(a[ix]+b[iy]+c[iz]);
        }else{
            break;
        }
    }
    vector<ll> ret;
    while(!pq.empty()){
        ret.push_back(pq.top());
        pq.pop();
    }
    sort(ret.begin(),ret.end(),greater<ll>());
    for(const auto &r:ret){
        cout << r << endl;
    }
    return 0;
}