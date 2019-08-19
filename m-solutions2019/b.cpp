#include<cstdio>
int main(){
    char s[16];
    scanf("%s",s);
    int lose=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='x')lose++;
    }
    printf("%s\n",(lose<8)?"YES":"NO");
    return 0;
}