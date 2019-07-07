//拡張ユークリッド互除法（ax+by=gcd(a,b) 返り値はgcd）
long long ext_gcd(long long a,long long b,long long &x,long long &y){
    //b==0ならa*1+b*0=a
    if(b==0){x=1;y=0;return a;}
    //a=qb+rとして、bx+qy=gなるx,y,gが得られたとすると、
    //aX+bY=g \iff (qb+r)X+bY=g \iff b(qX+Y)+rX=g
    //より、x=qX+Y, y=X \iff X=y, Y=x-qy
    long long q=a/b, g=ext_gcd(b,a-q*b,x,y), z=x-q*y;
    x=y; y=z;
    return g;
}

long long gcd(long long a,long long b){
    long long x,y;
    return ext_gcd(a,b,x,y);
}

long long inv(long long a,long long p){
    long long x,y;
    ext_gcd(a,p,x,y);
    return (x+p)%p;
}

//x[i]=i*(i-1)*...*2*1
void make_factorial(long long *x, int len, long long p){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*i)%p;
}

//x[i]=a*a*...*a
void make_power(long long *x, long long a, int len, long long p){
    x[0]=1;
    for(int i=1;i<len;i++)x[i]=(x[i-1]*a)%p;
}

long long ncr(long long n,long long r,long long *fct,long long p){
    if(n<0||n<r||r<0)return 0;
    return (fct[n]*inv(fct[r],p)%p)*inv(fct[n-r],p)%p;
}

long long npr(long long n,long long r,long long *fct,long long p){
    if(n<0||n<r||r<0)return 0;
    return fct[n]*inv(fct[r],p)%p;
}
