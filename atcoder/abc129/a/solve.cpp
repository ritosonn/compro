#include<cstdio>
#include<algorithm>
int main(){
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    printf("%d\n",std::min(p+q,std::min(q+r,r+p)));
    return 0;
}