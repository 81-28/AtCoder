// https://atcoder.jp/contests/abc405/tasks/abc405_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
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

    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    ll ans=0;
    ll s=sum(a);
    rep(i,n-1) {
        s-=a[i];
        ans+=a[i]*s;
    }
    print(ans);

    return 0;
}
