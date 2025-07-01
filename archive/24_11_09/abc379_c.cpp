// https://atcoder.jp/contests/abc379/tasks/abc379_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vll x(m),a(m);
    map<ll,ll> mp;
    cin >> x >> a;
    if (sum(a) != n) {
        print(-1);
        return 0;
    }
    if (n == m) {
        print(0);
        return 0;
    }
    rep(i,m) {
        mp[x[i]] = a[i];
    }
    sort(all(x));
    rep(i,m) a[i] = mp[x[i]];
    ll ans = 0;
    // tail : 今埋まっている最小値
    ll tail = n+1;
    for (ll i=m-1; i>=0; i--) {
        tail -= a[i];
        if (tail >= x[i]) {
            ans += a[i]*(a[i]-1)/2+(tail-x[i])*a[i];
        } else {
            print(-1);
            return 0;
        }
    }
    if (tail == 1) print(ans);
    else print(-1);

    return 0;
}
