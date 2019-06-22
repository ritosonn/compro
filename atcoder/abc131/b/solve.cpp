#include<cstdio>
#include<algorithm>
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    int lsum=0;
    for(int i=1;i<=n;i++)lsum+=l+i-1;
    if(l>0)lsum-=l;
    if(l+n-1<0)lsum-=l+n-1;
    printf("%d\n",lsum);
    return 0;
}