#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    string s,t;
    int q;
    cin >> s >> t >> q;
    //cnt_s[i]=s[0,...,i)にあるAの数-s[0,...,i)にあるBの数
    vector<int> cnt_s(s.size()+1), cnt_t(t.size()+1);
    cnt_s[0]=0;
    cnt_t[0]=0;
    loop(i,s.size())cnt_s[i+1]=cnt_s[i]+(s[i]=='A'?1:-1);
    loop(i,t.size())cnt_t[i+1]=cnt_t[i]+(t[i]=='A'?1:-1);
    loop(i,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(((cnt_s[b]-cnt_s[a-1])-(cnt_t[d]-cnt_t[c-1]))%3==0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}