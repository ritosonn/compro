#include<cstdio>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",(k==1?0:(n-k)));
    return 0;
}