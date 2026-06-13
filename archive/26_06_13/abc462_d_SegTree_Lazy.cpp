// https://atcoder.jp/contests/abc462/tasks/abc462_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()

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

    int n,d;
    cin >> n >> d;
    v<pii> p(n);
    for (auto&[b,a]:p) cin >> a >> b;
    sort(all(p));
    int mx=p.rbegin()->first;
    v<S_add_sum> init(mx+1,{0,1});
    lazy_segtree<S_add_sum, op_add_sum, e_add_sum, F_add_sum, mapping_add_sum, composition_add_sum, id_add_sum> t(init);
    int ans=0;
    for (auto[b,a]:p) {
        if (b-a<d) continue;
        ans+=t.prod(a+d,b+1).value;
        t.apply(a+d,b+1,1);
    }
    print(ans);

    return 0;
}
