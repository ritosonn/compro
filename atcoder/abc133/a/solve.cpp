#include<cstdio>
#include<algorithm>
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    printf("%d\n",std::min(a*n,b));
    return 0;
}