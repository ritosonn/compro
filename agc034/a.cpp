#include<cstdio>
#include<algorithm>
char s[200001];
int main(){
    int n,a,b,c,d;
    scanf("%d%d%d%d%d%s",&n,&a,&b,&c,&d,s);
    a--;
    b--;
    c--;
    d--;
    for(int i=a;i<c;i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            printf("No\n");
            return 0;
        }
    }
    for(int i=b;i<d;i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            printf("No\n");
            return 0;
        }
    }
    if(c<d){
        printf("Yes\n");
        return 0;
    }
    for(int i=b;i<=d-2;i++){
        if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
