// https://atcoder.jp/contests/abc442/tasks/abc442_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return a+b;}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    cin >> a;
    segtree<S,op,e> t(a);
    while (q--) {
        int m;
        cin >> m;
        if (m==1) {
            int x;
            cin >> x;
            int tmp=t.get(x);
            t.set(x,t.get(x-1));
            t.set(x-1,tmp);
        } else {
            int l,r;
            cin >> l >> r;
            print(t.prod(--l,r));
        }
    }

    return 0;
}
