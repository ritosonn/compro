#include<cstdio>
int a[200001],b[200001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    int winner=1,strongest=1;
    for(int i=2;i<=n;i++){
        int tern_winner=(a[winner]+b[i]-1)/b[i];
        int tern_i=(a[i]+b[winner]-1)/b[winner];
        if(tern_i>tern_winner){
            winner=i;
            strongest=i;
        }else if(tern_i==tern_winner){
            strongest=-1;
        }
    }
    if(strongest==-1){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i!=strongest){
            int tern_strongest=(a[strongest]+b[i]-1)/b[i];
            int tern_i=(a[i]+b[strongest]-1)/b[strongest];
            if(tern_i>=tern_strongest){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n",strongest);
    return 0;
}