#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define loop(i, n) rep(i, 0, n)
using namespace std;
using ll = long long;
template<class T, class Compare=less<T>> class SlideMinimum {
    deque<int> deq; vector<T> a; Compare cmp; int L, R;
public:
    SlideMinimum(const vector<T> &a): a(a), cmp(Compare()), L(0), R(0) {}
    inline void inc_L() { if(deq.front() == L++) deq.pop_front(); }
    inline void inc_R() { while(!deq.empty() && !cmp(a[deq.back()], a[R])) deq.pop_back(); deq.push_back(R++); }
    inline void slide_L(const int l) { assert(L<=l); while(L<l)inc_L(); }
    inline void slide_R(const int r) { assert(R<=r); while(R<r)inc_R(); }
    inline void slide(const int l, const int r) { if(R<=l){deq.clear(); L=R=l; } slide_R(r); slide_L(l); }
    inline void clear() { deq.clear(); L=R=0; }
    inline int getIndex() const { return deq.front(); }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    loop(i, n) cin >> p[i];
    //cnt_sorted=（k-1個以上ソート済みである区間の数）
    int cnt_sorted=0,cnt=0;
    loop(i,n-1){
        if(p[i]<p[i+1])++cnt;
        else cnt=0;
        if(cnt==k-1)++cnt_sorted;
    }
    SlideMinimum<int> slide_min(p);
    SlideMinimum<int,greater<int>> slide_max(p);
    int ans=1+min(0,1-cnt_sorted);
    loop(i,n-k){
        //      [i,i+k)と[i+1,i+k+1)をソートしたときに配列が等しい
        // <==> [i,i+k+1)の最小値がp[i],最大値がp[i+k]
        slide_min.slide(i,i+k+1);
        slide_max.slide(i,i+k+1);
        if(slide_min.getIndex()!=i || slide_max.getIndex()!=i+k)++ans;
    }
    cout << ans << endl;
    return 0;
}