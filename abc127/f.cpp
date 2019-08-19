#include<cstdio>
#include<queue>
#include<vector>
using ll = long long;
constexpr ll infty=1e15;
int main(){
    int q;
    //sum_i |x-a_i|のグラフが折れ曲がる（傾きが1増加する）位置を
    //l_n<=...<=l_1<=r_1<=...<=r_nとし、2つのpriority queueで管理：
    //lower=[l_n,...,l_1],higher=[r_1,...,r_n]
    std::priority_queue<ll> lower;
    std::priority_queue<ll,std::vector<ll>,std::greater<ll>> higher;
    ll sum_b=0,min_a=0;
    lower.push(-infty);
    higher.push(infty);
    //argmin(f)==[lower.top(),higher.top()]が常に成り立つようにする
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int j;
        scanf("%d",&j);
        if(j==1){//1 a b -> f(x)をf(x)+|x-a|+bで置き換える
            ll a,b;
            scanf("%lld%lld",&a,&b);
            sum_b+=b;
            if(a<lower.top()){
                //   [l_n,...,l_1],[r_1,...,r_n]
                //-> [l_n,...,a,a,...,l_2],[l_1,r_1,...,r_n]
                lower.push(a);
                lower.push(a);
                auto t=lower.top();
                lower.pop();
                higher.push(t);
                //最小値はl_1-aだけ増加
                min_a+=(t-a);
            }else if(a>higher.top()){
                //   [l_n,...,l_1],[r_1,...,r_n]
                //-> [l_n,...,l_1,r_1],[r_2,...,a,a,...,r_n]
                higher.push(a);
                higher.push(a);
                auto t=higher.top();
                higher.pop();
                lower.push(t);
                //最小値はa-r_1だけ増加
                min_a+=(a-t);
            }else{
                //   [l_n,...,l_1],[r_1,...,r_n]
                //-> [l_n,...,l_1,a],[a,r_1,...,r_n]
                lower.push(a);
                higher.push(a);
                //最小値は変化しない
            }
            //printf("%lld %lld %lld %lld\n",lower.top(),higher.top(),min_a,sum_b);
        }else{//2 -> min(argmin_x f(x))とmin(f(x))を出力する
            printf("%lld %lld\n",lower.top(),min_a+sum_b);
        }
    }

    return 0;
}