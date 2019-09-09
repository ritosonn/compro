#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
using pii=pair<int,int>;
int main(){
    int r,c,n;
    cin >> r >> c >> n;
    vector<pii> pq;
    loop(i,n){
        int x[2],y[2];
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        bool flg[2];
        loop(j,2)flg[j]=(x[j]==0||x[j]==r||y[j]==0||y[j]==c);
        if(flg[0]&&flg[1]){
            loop(j,2){
                int tmp;
                if(x[j]==0)tmp=y[j];//[0,c]
                else if(x[j]==r)tmp=c+r+c-y[j];//[c+r,c+r+c]
                else if(y[j]==c)tmp=c+x[j];//(c,c+r)
                else if(y[j]==0)tmp=c+r+c+r-x[j];//(c+r+c,c+r+c+r)
                pq.push_back(pii(tmp,i));
            }
        }
    }
    sort(pq.begin(),pq.end());
    stack<int> qu;
    for(auto &v:pq){
        int i=v.second;
        if(!qu.empty()&&qu.top()==i)qu.pop();
        else qu.push(i);
    }
    cout << (qu.empty()?"YES":"NO") << endl;
    return 0;
}