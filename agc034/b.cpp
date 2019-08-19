#include<cstdio>
char s[200001];
int main(){
    scanf("%s",s);
    long long cnt=0;
    int possibleA=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='A')possibleA++;
        else if(s[i]=='B'){
            if(s[i+1]=='\0')break;
            if(s[i+1]=='C'){
                cnt+=possibleA;
                i++;
            }else{
                possibleA=0;
            }
        }else{
            possibleA=0;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}