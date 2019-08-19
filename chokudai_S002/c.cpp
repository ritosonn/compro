#include<cstdio>
int main(){
    int n;
    long long a,b,maxsum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        if(a+b>maxsum)maxsum=a+b;
    }
    printf("%lld\n",maxsum);
    return 0;
}