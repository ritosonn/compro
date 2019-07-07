#include<cstdio>
using ll=long long;
ll a[99999];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    ll half_sum[2]={0,0};
    for(int i=0;i<n;i++)half_sum[i%2]+=a[i];
    ll total=(half_sum[0]+half_sum[1])/2;
    ll tmp=half_sum[0]-total;
    printf("%lld",2*tmp);
    for(int i=0;i<n-1;i++){
        tmp=a[i]-tmp;
        printf(" %lld",2*tmp);
    }
    printf("\n");
    return 0;
}