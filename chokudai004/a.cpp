#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(i,n) rep2(i,0,n)
using namespace std;
using timer = chrono::system_clock;
using ll = long long;
constexpr int use_time=2900;
int n,b[3],l[30][30],r[30][30],t[30][30],score_memo[30][30]={};
int score(int i,int j){
    int ret=0;
    rep(j1,n){
        int tmp=0;
        rep2(j2,j1,n){
            tmp+=t[i][j2];
            if(tmp>40)break;
            rep(m,3)if(tmp==b[m])ret+=b[m];
        }
    }
    rep(i1,n){
        int tmp=0;
        rep2(i2,i1,n){
            tmp+=t[i2][j];
            if(tmp>40)break;
            rep(m,3)if(tmp==b[m])ret+=b[m];
        }
    }
    return ret;
}
int main(){
    auto begin=timer::now();
    cin >> n >> b[0] >> b[1] >> b[2];
    rep(i,n)rep(j,n)cin >> l[i][j];
    rep(i,n)rep(j,n)cin >> r[i][j];
    random_device rnd;
    mt19937 mt(rnd());
    std::vector<uniform_int_distribution<>> vals_rand(100);
    rep(i,100)vals_rand[i]=uniform_int_distribution<>(i/10,i%10);
    rep(i,n)rep(j,n)t[i][j]=vals_rand[l[i][j]*10+r[i][j]](mt);
    uniform_int_distribution<> area_rand(0,29);
    uniform_real_distribution<> annealing_rand(0,1);
    //int cnt=0;
    while(true){
        auto tmt=chrono::duration_cast<chrono::milliseconds>(timer::now()-begin).count();
        if(tmt>use_time)break;
        int i=area_rand(mt),j=area_rand(mt);
        if(l[i][j]==r[i][j])continue;
        int tij_old=t[i][j],tij_new=vals_rand[l[i][j]*10+r[i][j]](mt);
        if(tij_new==tij_old)continue;
        if(score_memo[i][j]==0)score_memo[i][j]=score(i,j);
        t[i][j]=tij_new;
        int score_new=score(i,j);
        if(score_new<score_memo[i][j]&&annealing_rand(mt)*tmt>2)t[i][j]=tij_old;
        else score_memo[i][j]=score_new;
        //++cnt;
    }
    //cout << cnt << endl;
    rep(i,n)rep(j,n)cout << t[i][j] << ((j==n-1)?'\n':' ');
    return 0;
}