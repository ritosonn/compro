#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using pii=std::pair<int,int>;
using piii=std::pair<int,pii>;
class UnionFind{
private:
    int length, numComponent;
    //parent[x]=xの親の番号 ............. xに親が存在する場合,
    //parent[x]=-(xを含む集合の要素数) ... xが親である場合
    int *parent;
    int *rank;
public:
    UnionFind(int l);
    ~UnionFind();
    int root(int x);
    void unite(int x,int y);
    bool isSameTree(int x,int y);
    int sizeOf(int x);
    int component();
};
UnionFind::UnionFind(int l){
    length=l;
    numComponent=l;
    parent=new int[l];
    for(int i=0;i<l;i++)parent[i]=-1;
    rank=new int[l];
    for(int i=0;i<l;i++)rank[i]=0;
}
UnionFind::~UnionFind(){
    delete[] parent;
    delete[] rank;
}
int UnionFind::root(int x){
    if(parent[x]<0)return x;
    return parent[x]=root(parent[x]);
}
void UnionFind::unite(int x,int y){
    int rx=root(x),ry=root(y);
    if(rx!=ry){
        numComponent--;
        if(rank[rx]>rank[ry]){
            parent[rx]+=parent[ry];
            parent[ry]=rx;
        }
        else{
            if(rank[rx]==rank[ry])rank[ry]++;
            parent[ry]+=parent[rx];
            parent[rx]=ry;
        }
    }
}
bool UnionFind::isSameTree(int x,int y){
    return root(x)==root(y);
}
int UnionFind::component(){
    return numComponent;
}
int UnionFind::sizeOf(int x){
    return -parent[root(x)];
}
int main(){
    int n;
    scanf("%d",&n);
    std::vector<piii> vp;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vp.push_back({i,{x,y}});
    }
    UnionFind uf_all(n);
    //union about x
    std::sort(vp.begin(),vp.end(),[](piii a,piii b){return a.second.first<b.second.first;});
    for(int i=1;i<n;i++){
        if(vp[i].second.first==vp[i-1].second.first){
            uf_all.unite(vp[i].first,vp[i-1].first);
        }
    }
    //union about y
    std::sort(vp.begin(),vp.end(),[](piii a,piii b){return a.second.second<b.second.second;});
    for(int i=1;i<n;i++){
        if(vp[i].second.second==vp[i-1].second.second){
            uf_all.unite(vp[i].first,vp[i-1].first);
        }
    }
    //count x_size and y_size
    std::sort(vp.begin(),vp.end(),[](piii a,piii b){return a.first<b.first;});
    std::vector<std::set<int>> x_sets(n),y_sets(n);
    for(int i=0;i<n;i++){
        x_sets[uf_all.root(i)].emplace(vp[i].second.first);
        y_sets[uf_all.root(i)].emplace(vp[i].second.second);
    }
    //count y_size
    long long ans=0;
    for(int i=0;i<n;i++){
        if(uf_all.root(i)==i){
            long long point_num=uf_all.sizeOf(i), x_size=x_sets[i].size(), y_size=y_sets[i].size();

            //std::cout << x_size << "," << y_size << "," << point_num << "\n";
            if(x_size>=2&&y_size>=2){
                ans+=x_size*y_size-point_num;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}