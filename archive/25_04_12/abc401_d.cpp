// https://atcoder.jp/contests/abc401/tasks/abc401_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using pll=pair<ll,ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,k;
    string s;
    cin >> n >> k >> s;
    ll o=0;
    string t=s;
    rep(i,n) {
        if (s[i]=='o') o++;
        if (s[i]=='?') {
            if ((i&&s[i-1]=='o')||(i<n-1&&s[i+1]=='o')) t[i]='.';
        }
    }
    if (o==k) {
        rep(i,n)cout<<((t[i]=='?')?'.':t[i]);
        cout<<'\n';
        return 0;
    }

    v<pll> a;
    ll c=0;
    rep(i,n) {
        if (t[i]=='?') c++;
        else {
            if (c) {
                a.pb({c,i-c});
                c=0;
            }
        }
    }
    if (c) a.pb({c,n-c});
    for (auto p:a) {
        o+=(p.first+1)/2;
    }
    if (o!=k) {
        print(t);
        return 0;
    }
    for (auto p:a) {
        if (p.first%2) {
            rep(i,p.first) {
                t[p.second+i]=i%2?'.':'o';
            }
        }
    }
    print(t);

    return 0;
}
