// https://atcoder.jp/contests/abc301/tasks/abc301_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    ll n;
    cin >> s >> n;
    ll nn=n,m=s.size();
    vll a;
    rep(i,m) {
        if (s[i]=='1') n-=(ll)pow(2,m-1-i);
        if (s[i]=='?') a.pb(m-1-i);
    }
    if (n<0) {
        print(-1);
        return 0;
    }
    for (ll i:a) {
        ll p=pow(2,i);
        if (p<=n) n-=p;
    }
    print(nn-n);

    return 0;
}
