#include<cstdio>
using ll=long long;
ll a[100000];
int main(){
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    int r=0;
    ll part_sum=0;
    ll count=0;
    for(int l=0;l<n;l++){
        while(r<n&&part_sum<k){
            part_sum+=a[r];
            r++;
        }
        if(part_sum<k)break;
        //[l..r-1]の和がk以上なので、[l..(r+s)]の和もすべてk以上
        count+=n-r+1;
        part_sum-=a[l];
    }
    printf("%lld\n",count);
    return 0;
}