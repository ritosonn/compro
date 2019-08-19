#include<cstdio>
int main(){
    int k,x;
    scanf("%d%d",&k,&x);
    for(int i=x-k+1;i<x+k;i++){
        printf("%d%c",i,(i!=x+k-1)?' ':'\n');
    }
    return 0;
}