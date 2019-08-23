#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    //{6k}から任意個、{6k-2,6k-4},{12k-3,12k-9}から1つ以上とってできる集合は常に条件を満たす
    //最小で{2,4,3,9}の4個,最大で{1..30000}\cap {6k,6k+2,6k+3,6k+4}=20000個なのでこれを構築すれば十分
    if(n==3)cout << "2 3 25" << endl;
    else{
        cout << "4 2 9 3";
        n-=4;
        int k=2;
        while(n>=2&&k<=5000){
            cout << " " << 6*k-4 << " " << 6*k-2;
            ++k;
            n-=2;
        }
        k=2;
        while(n>=2&&k<=2500){
            cout << " " << 12*k-9 << " " << 12*k-3;
            ++k;
            n-=2;
        }
        k=1;
        while(n>=1){
            cout << " " << 6*k;
            ++k;
            --n;
        }
        cout << endl;
    }
    return 0;
}