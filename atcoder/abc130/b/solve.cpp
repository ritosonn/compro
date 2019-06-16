#include<cstdio>
int main(){
    int n,x,l[101];
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)scanf("%d",&l[i]);
    int d=0,cnt=1;
    for(int i=1;i<=n;i++){
        d+=l[i];
        if(d<=x)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}