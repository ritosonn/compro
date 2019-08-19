#include<cstdio>
#include<algorithm>
int d[100000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&d[i]);
    std::sort(d,d+n);
    printf("%d\n",d[n/2]-d[n/2-1]);
    return 0;
}