// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,n,m;
    cin >> l >> n >> m;
    vi d(n-1);
    cin >> d;
    d.pb(0),d.pb(l);
    sort(all(d));
    int ans=0;
    // 左右で一番近い店舗を探す
    while (m--) {
        int k;
        cin >> k;
        auto itl=upper_bound(all(d),k);
        --itl;
        auto itr=lower_bound(all(d),k);
        ans+=min(*itr-k,k-*itl);
    }
    print(ans);

    return 0;
}
