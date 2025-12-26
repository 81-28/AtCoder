// https://atcoder.jp/contests/joi2017ho/tasks/joi2017ho_a

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q,s,t;
    cin >> n >> q >> s >> t;
    vi a(n+1);
    cin >> a;
    int ans=0;
    rep1(i,n) {
        if (a[i]>a[i-1]) ans-=s*(a[i]-a[i-1]);
        else ans-=t*(a[i]-a[i-1]);
    }
    v<S> init(n+1);
    init[0]=a[0];
    rep1(i,n) init[i]=a[i]-a[i-1];
    segtree<S,op,e> seg(init);
    while (q--) {
        int l,r,x;
        cin >> l >> r >> x;
        // 境界の値で答えを調整
        int l_l=seg.prod(0,l);
        int l_r=seg.prod(0,l+1);
        if (l_r>l_l) ans+=s*(l_r-l_l);
        else ans+=t*(l_r-l_l);
        l_r+=x;
        if (l_r>l_l) ans-=s*(l_r-l_l);
        else ans-=t*(l_r-l_l);
        if (r!=n) {
            int r_l=seg.prod(0,r+1);
            int r_r=seg.prod(0,r+2);
            if (r_r>r_l) ans+=s*(r_r-r_l);
            else ans+=t*(r_r-r_l);
            r_r-=x;
            if (r_r>r_l) ans-=s*(r_r-r_l);
            else ans-=t*(r_r-r_l);
        }
        print(ans);
        seg.set(l,seg.get(l)+x);
        if (r!=n) seg.set(r+1,seg.get(r+1)-x);
    }

    return 0;
}
