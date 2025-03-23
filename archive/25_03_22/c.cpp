// https://atcoder.jp/contests/abc398/tasks/abc398_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rall(v) v.rbegin(),v.rend()
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
    map<ll,ll> m;
    map<ll,ll> mp;
    mp[-1]=-1;
    rep(i,n) {
        m[a[i]]++;
        mp[a[i]] = i+1;
    }
    sort(rall(a));
    ll ans=-1;
    rep(i,n) {
        if (m[a[i]]==1) {
            ans=a[i];
            break;
        }
    }
    print(mp[ans]);

    return 0;
}
