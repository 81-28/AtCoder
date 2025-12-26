// https://atcoder.jp/contests/abc223/tasks/abc223_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

using S=int;
S op(S a,S b){return min(a,b);}
S e(){return INF;}
using F=int;
S mapping(F f,S x){return f+x;}
F composition(F f,F g){return f+g;}
F id(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    vi sm(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+(s[i-1]=='('?1:-1);
    // 区間加算,区間最小値のセグ木で、上り(,下り)を管理
    // l,rが同じ高さで、その間で高さが端を下回らない場合正しい
    lazy_segtree<S,op,e,F,mapping,composition,id> t(sm);
    while (q--) {
        int m,l,r;
        cin >> m >> l >> r;
        --l,--r;
        if (m==1) {
            if (s[l]==s[r]) continue;
            t.apply(l+1,r+1,s[l]==')'?2:-2);
            s[l]^=1,s[r]^=1;
        } else {
            // これで弾かれる場合、最小値の条件も満たさないので不要
            // if (s[l]!='('||s[r]!=')') {
            //     YesNo(0);
            //     continue;
            // }
            int base=t.get(l);
            YesNo(base==t.get(r+1) && t.prod(l+1,r+1)>=base);
        }
    }

    return 0;
}
