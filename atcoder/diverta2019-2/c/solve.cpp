#include<cstdio>
#include<algorithm>
int a[100000];
int main(){
    int n,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=std::abs(a[i]);
    }
    std::sort(a,a+n);
    if(a[0]>=0){
        printf("%d\n",sum-2*a[0]);
        int tmp=a[0];
        for(int i=1;i<n-1;i++){
            printf("%d %d\n",tmp,a[i]);
            tmp-=a[i];
        }
        printf("%d %d\n",a[n-1],tmp);
    }else if(a[n-1]<=0){
        printf("%d\n",sum+2*a[n-1]);
        int tmp=a[n-1];
        for(int i=0;i<n-1;i++){
            printf("%d %d\n",tmp,a[i]);
            tmp-=a[i];
        }
    }else{
        printf("%d\n",sum);
        int l=0;
        while(a[l]<=0)l++;
        int tmp=a[0];
        for(int i=l+1;i<n;i++){
            printf("%d %d\n",tmp,a[i]);
            tmp-=a[i];
        }
        printf("%d %d\n",a[l],tmp);
        tmp=a[l]-tmp;
        for(int i=1;i<l;i++){
            printf("%d %d\n",tmp,a[i]);
            tmp-=a[i];
        }
    }
    return 0;
}