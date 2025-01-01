// https://atcoder.jp/contests/abc334/tasks/abc334_d

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

    int n,q;
    cin >> n >> q;
    vll r(n);
    cin >> r;
    sort(all(r));
    for (int i=1; i<n; i++) {
        r[i]+=r[i-1];
    }
    ll x;
    rep(i,q) {
        cin >> x;
        auto it=upper_bound(all(r),x);
        print(distance(r.begin(),it));
    }

    return 0;
}
