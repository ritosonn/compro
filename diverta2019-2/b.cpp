#include<cstdio>
#include<vector>
#include<algorithm>
int main(){
    int n;
    std::vector<std::pair<int,int>> vxy,vpq;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vxy.push_back({x,y});
    }
    std::sort(vxy.begin(),vxy.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vpq.push_back({vxy[j].first-vxy[i].first, vxy[j].second-vxy[i].second});
        }
    }
    int num_cost0_max=0;
    for(auto &pq:vpq){
        int num_cost0=0;
        int p=pq.first,q=pq.second;
        for(auto &xy:vxy){
            int x=xy.first,y=xy.second;
            for(auto &next_xy:vxy){
                if(next_xy.first==x-p&&next_xy.second==y-q){
                    num_cost0++;
                }
            }
        }
        num_cost0_max=std::max(num_cost0,num_cost0_max);
    }
    printf("%d\n",n-num_cost0_max);
    return 0;
}