#include<cstdio>
#include<algorithm>
char s[2000][2001];
//len[0]:横、len[1]:縦
int len[2][2000][2000];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++)scanf("%s",s[i]);
    for(int i=0;i<h;i++){
        int l=0;
        while(l<w){
            if(s[i][l]=='#'){
                len[0][i][l]=0;
                l++;
            }else{
                int r=l+1;
                while(r<w&&s[i][r]=='.')r++;
                for(int j=l;j<r;j++)len[0][i][j]=r-l;
                l=r+1;
            }
        }
    }
    for(int j=0;j<w;j++){
        int u=0;
        while(u<h){
            if(s[u][j]=='#'){
                len[1][u][j]=0;
                u++;
            }else{
                int d=u+1;
                while(d<h&&s[d][j]=='.')d++;
                for(int i=u;i<d;i++)len[1][i][j]=d-u;
                u=d+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                ans=std::max(ans,len[0][i][j]+len[1][i][j]-1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}