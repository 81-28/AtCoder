// https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_a

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return max(a,b);}
S e(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> a(n+1);
    rep(i,n+1) {
        auto&[ai,j]=a[i];
        cin >> ai;
        j=i;
    }
    vi b(n);
    cin >> b;
    sort(all(a)),sort(all(b));
    v<S> init(n);
    rep(i,n) init[i]=max(a[i].f-b[i],0LL);
    segtree<S,op,e> t(init);
    vi ans(n+1);
    ans[a[n].s]=t.all_prod();
    // 使わないネクタイをズラす
    for (int i=n-1; i>=0; --i) {
        auto[ai,j]=a[i];
        t.set(i,max(a[i+1].f-b[i],0LL));
        ans[j]=t.all_prod();
    }
    rep(i,n+1) print(ans[i]);

    return 0;
}
