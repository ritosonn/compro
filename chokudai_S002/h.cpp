#include<cstdio>
#include<algorithm>
int main(){
    int n;
    long long a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",(std::abs(a-b)==0)?-1:std::abs(a-b));
    }
    return 0;
}