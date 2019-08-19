#include<cstdio>
char s[200001]={};
int main(){
    scanf("%s",s);
    int cnt=1,last_len=1,itr=1;
    while(s[itr]!='\0'){
        if(last_len==2){
            last_len=1;
            ++itr;
        }else if(s[itr]==s[itr-1]){
            if(s[itr+1]=='\0')break;
            last_len=2;
            itr+=2;
        }else{
            ++itr;
        }
        ++cnt;
    }
    printf("%d\n",cnt);
    return 0;
}