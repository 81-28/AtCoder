// https://atcoder.jp/contests/abc313/tasks/abc313_c

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

    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    ll s=sum(a);
    ll l=s/n,r=l+1;
    sort(all(a));
    ll ans1=0,ans2=0;
    rep(i,n) {
        if (a[i]<=l) ans1+=l-a[i];
        else ans2+=a[i]-r;
    }
    print(max(ans1,ans2));

    return 0;
}
