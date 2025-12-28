// https://atcoder.jp/contests/abc296/tasks/abc296_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


using S=int;
S op(S a,S b){return a+b;}
S e(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b=a;
    cin >> a >> b;
    map<int,int> mpa,mpb;
    rep(i,n) {
        ++mpa[--a[i]];
        ++mpb[--b[i]];
    }
    bool ok=0;
    for (auto[num,cnt]:mpa) {
        if (cnt>1) ok=1;
        if (mpb[num]==cnt) continue;
        YesNo(0);
        return 0;
    }
    if (ok) {
        YesNo(1);
        return 0;
    }
    segtree<S,op,e> ta(n),tb(n);
    int sma=0,smb=0;
    ta.set(a[n-1],1),tb.set(b[n-1],1);
    for (int i=n-2; i>=0; --i) {
        sma+=ta.prod(0,a[i]);
        ta.set(a[i],ta.get(a[i])+1);
        smb+=tb.prod(0,b[i]);
        tb.set(b[i],tb.get(b[i])+1);
    }
    YesNo((sma&1)==(smb&1));

    return 0;
}
