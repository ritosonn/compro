#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),a_cnt(n,0);
    loop(i,n)cin >> a[i];
    loop(i,n)a_cnt[a[i]]++;
    int a_max=*max_element(a.begin(),a.end());
    int a_min=*min_element(a.begin(),a.end());
    //次の条件を満たす木は構築できる
    // - a_minは1個, かつ a_min+1,...,a_maxは少なくとも2個, かつ a_maxは偶数 （M,M-1,...,m+1,m,m+1,...,Mに毛が生えたみたいな形）
    // - a_minは2個, かつ a_min+1,...,a_maxは少なくとも2個, かつ a_maxは奇数 （M,M-1,...,m+1,m,m,m+1,...,Mに毛が生えたみたいな形）
    //逆に、この形でないときは構築できない
    bool ans=(a_cnt[a_min]<=2)&&((a_cnt[a_min]==1)==(a_max%2==0));
    rep(i,a_min+1,a_max+1)ans=(ans&&a_cnt[i]>=2);
    cout << (ans?"Possible":"Impossible") << endl;
    return 0;
}