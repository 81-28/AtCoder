// https://atcoder.jp/contests/arc227/tasks/arc227_b

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(all(a));
    segtree<S,op,e> t(a.back()+1);
    multiset<int> s(all(a));
    vi ans(n);
    rep(i,n) {
        auto it=s.upper_bound(i);
        if (it==s.begin()) {
            YesNo(0);
            return 0;
        }
        ans[i]=*--it;
        if (t.prod(0,ans[i])!=ans[i]) {
            YesNo(0);
            return 0;
        }
        s.erase(it);
        t.set(ans[i],t.get(ans[i])+1);
    }
    YesNo(1);
    print(ans);

    return 0;
}
