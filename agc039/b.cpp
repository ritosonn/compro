#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
char s[200][201];
int d[200][200];
int n;
bool is_bipartite_graph(){
    vector<int> color(n,-1);
    color[0]=0;
    queue<int> qu;
    qu.push(0);
    while(!qu.empty()){
        int i=qu.front();
        qu.pop();
        loop(j,n){
            if(s[i][j]=='1'){
                if(i==j)continue;
                if(color[j]==-1){
                    color[j]=1-color[i];
                    qu.push(j);
                }else if(color[j]==color[i]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    cin >> n;
    loop(i,n)scanf("%s",s[i]);
    //二部グラフでなければ不可
    //理由：V_1, ..., V_k に分割できるなら、 V_奇数 と V_偶数 が二部グラフになっているから
    if(!is_bipartite_graph()){
        cout << -1 << endl;
        return 0;
    }
    //二部グラフのときはグラフの直径になる
    //理由：V_1,...,V_k 間はパスはあるので、直径以上の長さにはならない
    //また、直径を与えるパスの各頂点を V_1,...,V_k に入れれば、二部グラフなので過不足なく残りを割り振れる
    loop(i,n)loop(j,n)d[i][j]=((s[i][j]=='1')?1:10000);
    loop(i,n)d[i][i]=0;
    loop(k,n)loop(i,n)loop(j,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int ans=0;
    loop(i,n)loop(j,n)ans=max(ans,d[i][j]);
    cout << 1+ans << endl;
    return 0;
}