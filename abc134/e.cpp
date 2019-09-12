#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    multiset<int> st;
    loop(i,n){
        int a;
        cin >> a;
        auto itr=st.lower_bound(a);
        if(!st.empty() && itr!=st.begin()){
            --itr;
            st.erase(itr);
        }
        st.emplace(a);
    }
    cout << st.size() << endl;
    return 0;
}