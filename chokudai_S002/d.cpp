#include<cstdio>
#include<algorithm>
int main(){
    int n;
    long long a,b,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        sum+=std::max(a,b);
    }
    printf("%lld\n",sum);
    return 0;
}