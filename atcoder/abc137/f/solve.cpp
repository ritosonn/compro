#include<cstdio>
#include<array>
template<int p>
class mod_poly{
    std::array<int, p> val_;
public:
    mod_poly(){
        for(int i=0;i<p;i++)val_[i]=0;
    }
    mod_poly(int a){
        val_[i]=((a%p)+p)%p
        for(int i=1;i<p;i++)val_[i]=0;
    }
    mod_poly<p> &operator+=(const mod_poly<p> &a){
        for(int i=0;i<p;i++){
            val_[i]=(val_[i]+a.val_[i])%p;
        }
    }
    mod_poly<p> &operator*=(const mod_poly<p> &a){
        for(int i=0;i<p;i++){
            for(int j=0;j<p;j++){
                
            }
        }
    }
};

template<int p>
mod_poly<p> operator+(const mod_poly<p> &a, const mod_poly<p> &b){
    return mod_poly<p>(a)+=b;
}

template<int p>
mod_poly<p> operator*(const mod_poly<p> &a, const mod_poly<p> &b){
    return mod_poly<p>(a)*=b;
}