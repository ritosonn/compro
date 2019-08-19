#include<cstdio>
#include<cmath>
int main(){
    int n,d,x[10][10];
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&x[i][j]);
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d2=0;
            for(int k=0;k<d;k++)d2+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            int t=static_cast<int>(std::sqrt(d2));
            if(t*t==d2)count++;
        }
    }
    printf("%d\n",count);
    return 0;
}