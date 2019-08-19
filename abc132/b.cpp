#include<cstdio>
int main(){
    int p[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(p[i-1]<p[i]&&p[i]<p[i+1]||p[i-1]>p[i]&&p[i]>p[i+1])ans++;
    }
    printf("%d\n",ans);
    return 0;
}