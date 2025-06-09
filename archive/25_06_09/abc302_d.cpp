// https://atcoder.jp/contests/abc302/tasks/abc302_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<class T> constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m,d;
    cin >> n >> m >> d;
    vll a(n),b(m);
    cin >> a >> b;
    sort(all(a)),sort(all(b));
    ll ans=-1;
    rep(i,n) {
        auto it=upper_bound(all(b),a[i]+d);
        if (it==b.begin()) continue;
        --it;
        if (a[i]-d<=*it) chmax(ans,a[i]+*it);
    }
    print(ans);

    return 0;
}
