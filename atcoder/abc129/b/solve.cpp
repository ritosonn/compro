#include<cstdio>
#include<algorithm>
int main(){
    int n,w[100],ans=1e9;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&w[i]);
    for(int t=0;t<n;t++){
        int s1=0,s2=0;
        for(int i=0;i<t;i++)s1+=w[i];
        for(int i=t;i<n;i++)s2+=w[i];
        ans=std::min(ans,std::abs(s1-s2));
    }
    printf("%d\n",ans);
    return 0;
}