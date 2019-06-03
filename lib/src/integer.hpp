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