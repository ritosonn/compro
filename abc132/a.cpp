#include<cstdio>
int main(){
    char s[5];
    scanf("%s",s);
    int a[256]={};
    for(int i=0;i<4;i++)a[s[i]]++;
    for(int i=0;i<4;i++){
        if(a[s[i]]!=2){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}