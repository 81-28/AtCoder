// https://atcoder.jp/contests/abc388/tasks/abc388_c

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


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vll a(n);
    cin >> a;

    ll ans = 0;
    for (ll i=0; i<n-1; i++) {
        auto it=lower_bound(all(a),a[i]*2);
        if (it == a.end()) break;
        ans += distance(it,a.end());
    }
    print(ans);

    return 0;
}
