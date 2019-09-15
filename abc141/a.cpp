#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define loop(i,n) rep(i,0,n)
using namespace std;
using ll = long long;
int main(){
    string s;
    cin >> s;
    if(s=="Sunny")cout << "Cloudy" << endl;
    else if(s=="Cloudy")cout << "Rainy" << endl;
    else cout << "Sunny" << endl;
    return 0;
}