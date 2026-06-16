// https://atcoder.jp/contests/abc221/tasks/abc221_d

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
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct S_add_sum { int value; int size; };
using F_add_sum = int;
S_add_sum op_add_sum(S_add_sum a, S_add_sum b){ return {a.value + b.value, a.size + b.size}; }
S_add_sum e_add_sum(){ return {0, 0}; }
S_add_sum mapping_add_sum(F_add_sum f, S_add_sum x){ return { x.value + f * x.size, x.size }; }
F_add_sum composition_add_sum(F_add_sum f, F_add_sum g){ return f + g; }
F_add_sum id_add_sum(){ return 0; }


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    vi c;
    for (auto&[a,b]:p) {
        cin >> a >> b;
        c.pb(a);
        c.pb(a+b);
    }
    sort(all(c));
    uniq(c);
    int l=c.size();
    map<int,int> m;
    rep(i,l) m[c[i]]=i;
    v<S_add_sum> init(l-1);
    rep(i,l-1) init[i]={0,c[i+1]-c[i]};
    lazy_segtree<S_add_sum, op_add_sum, e_add_sum, F_add_sum, mapping_add_sum, composition_add_sum, id_add_sum> t(init);
    for (auto[a,b]:p) {
        t.apply(m[a],m[a+b],1);
    }
    vi ans(n,0);
    rep(i,l-1) {
        // 合計人数,幅
        auto[sm,num]=t.prod(i,i+1);
        int cnt=sm/num;
        if (!cnt) continue;
        ans[cnt-1]+=num;
    }
    print(ans);

    return 0;
}
