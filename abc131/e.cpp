#include<cstdio>
#include<queue>
using pii=std::pair<int,int>;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if((n-1)*(n-2)/2<k){
        printf("-1\n");
        return 0;
    }
    std::queue<pii> q;
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            q.push({i,j});
        }
    }
    for(int i=0;i<k;i++){
        q.pop();
    }
    printf("%d\n",n-1+(int)q.size());
    for(int i=2;i<=n;i++){
        printf("1 %d\n",i);
    }
    while(!q.empty()){
        pii p=q.front();
        printf("%d %d\n",p.first,p.second);
        q.pop();
    }
    return 0;
}