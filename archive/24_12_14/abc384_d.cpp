// https://atcoder.jp/contests/abc384/tasks/abc384_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,s;
    cin >> n >> s;
    vll a(n);
    cin >> a;
    ll su = sum(a);
    s %= su;
    vll b = a;
    b.insert(b.end(),all(a));
    vll sb(n*2);
    sb[0] = b[0];
    for (int i=1; i<n*2; i++) sb[i] = sb[i-1]+b[i];
    rep(i,n*2) {
        ll t = sb[i]-s;
        if (i!=0) {
            auto it = lower_bound(sb.begin(),sb.begin()+(i-1),t);
            if (t%su==*it%su) {
                YesNo(1);
                return 0;
            }
        } else {
            if (t==sb[0]) {
                YesNo(1);
                return 0;
            }
        }
    }
    YesNo(0);

    return 0;
}
