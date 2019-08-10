#include<cstdio>
#include<algorithm>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",std::max(std::max(a+b,a-b),a*b));
    return 0;
}