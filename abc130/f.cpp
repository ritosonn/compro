#include<cstdio>
#include<vector>
#include<algorithm>
//線分={始点,終点}（始点<=終点）
using lseg=std::pair<double,double>;
lseg init(){
    return {0,-1};
}
bool is_valid(lseg a){
    return a.first<=a.second;
}
void add_point(lseg &a,double x){
    if(!is_valid(a)) a={x,x};
    else a={std::min(a.first,x),std::max(a.second,x)};
}
lseg merge(lseg a,lseg b){
    if(!is_valid(a))return b;
    if(!is_valid(b))return a;
    return {std::min(a.first,b.first),std::max(a.second,b.second)};
}
lseg merge(lseg a,lseg b,lseg c){
    return merge(merge(a,b),c);
}
lseg move(lseg a,double t){
    return {a.first+t,a.second+t};
}
double len(lseg a){
    if(!is_valid(a)) return 0;
    return a.second-a.first;
}
double len(double t,lseg a_plus,lseg a_const,lseg a_minus){
    return len(merge(move(a_plus,t),a_const,move(a_minus,-t)));
}
//a+v_a*t==b+v_b*tなるt>=0が存在すればevに追加
void add_event(std::vector<double> &ev, double a, double v_a, double b, double v_b){
    if(v_a!=v_b&&(a-b)/(v_b-v_a)>=0)ev.push_back((a-b)/(v_b-v_a));
}
void add_event(std::vector<double> &ev, lseg a, double v_a, lseg b, double v_b){
    if(is_valid(a)&&is_valid(b)){
        add_event(ev,a.first,v_a,b.first,v_b);
        add_event(ev,a.first,v_a,b.second,v_b);
        add_event(ev,a.second,v_a,b.first,v_b);
        add_event(ev,a.second,v_a,b.second,v_b);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    lseg x_plus=init(),x_const=init(),x_minus=init(),y_plus=init(),y_const=init(),y_minus=init();
    for(int i=0;i<n;i++){
        int x,y;
        char d;
        scanf("%d%d %c",&x,&y,&d);
        if(d=='R'){
            add_point(x_plus,x);
            add_point(y_const,y);
        }else if(d=='L'){
            add_point(x_minus,x);
            add_point(y_const,y);
        }else if(d=='U'){
            add_point(x_const,x);
            add_point(y_plus,y);
        }else{
            add_point(x_const,x);
            add_point(y_minus,y);
        }
    }
    std::vector<double> ev;
    ev.push_back(0);
    add_event(ev,x_plus,1,x_const,0);
    add_event(ev,x_plus,1,x_minus,-1);
    add_event(ev,x_minus,-1,x_const,0);
    add_event(ev,y_plus,1,y_const,0);
    add_event(ev,y_plus,1,y_minus,-1);
    add_event(ev,y_minus,-1,y_const,0);
    double area_min=1e30;
    for(auto &t:ev){
        auto area_tmp=len(t,x_plus,x_const,x_minus)*len(t,y_plus,y_const,y_minus);
        if(area_tmp<area_min)area_min=area_tmp;
    }
    printf("%.10lf\n",area_min);
    return 0;
}