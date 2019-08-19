#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
int main(){
    int n;
    scanf("%d",&n);
    std::vector<std::string> vs;
    for(int i=0;i<n;i++){
        std::string s;
        std::cin >> s;
        std::sort(s.begin(),s.end());
        vs.push_back(s);
    }
    std::sort(vs.begin(),vs.end());
    long long cnt=0;
    int conti=0;
    for(int i=1;i<n;i++){
        if(vs[i]==vs[i-1]){
            ++conti;
            cnt+=conti;
        }else{
            conti=0;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}