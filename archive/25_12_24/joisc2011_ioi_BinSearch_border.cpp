// http://atcoder.jp/contests/joisc2011/tasks/joisc2011_ioi

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int k,n,m;
    cin >> k >> n >> m;
    vi p(k);
    cin >> p;
    // 金メダルを与えられる人数(切り上げ)
    int gn=(k-1)/12+1;
    vi a,b,c=p;
    sort(all(c));
    int dif=100*(n-m);
    rep(i,k) {
        // 最悪
        auto it=upper_bound(all(c),p[i]-dif);
        // 自分自身も居る(n-m==0の場合、自分は居ないとする)
        if (c.end()-it<gn+(n!=m)) a.pb(i+1);
        // 最良
        it=upper_bound(all(c),p[i]+dif);
        if (c.end()-it<gn) b.pb(i+1);
    }
    for (int val:a) print(val);
    print("--------");
    for (int val:b) print(val);

    return 0;
}
