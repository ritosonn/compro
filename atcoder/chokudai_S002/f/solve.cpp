#include<cstdio>
#include<vector>
#include<set>
using p = std::pair<int,int>;
int main(){
    int n,a,b;
    std::set<p> s;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(a<b)s.insert({a,b});
        else s.insert({b,a});
    }
    printf("%d\n",s.size());
    return 0;
}