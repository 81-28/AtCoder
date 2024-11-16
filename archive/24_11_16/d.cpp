// https://atcoder.jp/contests/abc380/tasks/abc380_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;
    ll n = s.size();
    string rs = "";
    for (ll i=0; i<n; i++) {
        if (isupper(s[i])) {
            rs += tolower(s[i]);
        } else {
            rs += toupper(s[i]);
        }
    }
    ll m = n;
    for (; m < (ll)(1e18/2); m*=2) {}
    m/=n;
    v<char> ans;
    ll k;
    ll b,r;
    int c;
    ll kl = 0,kr = m*2,km;
    rep(i,q) {
        cin >> k;
        k--;
        b = k/n;
        b++;
        r = k%n;
        kl = 1,kr = m*2;
        c = 0;
        while(kl<kr) {
            km = (kl+kr-1)/2;
            if (b <= km) kr = km;
            if (b > km) {
                kl = km+1;
                c ^= 1;
            }
        }
        if (c) {
            ans.pb(rs[r]);
        } else {
            ans.pb(s[r]);
        }
    }
    print(ans);

    return 0;
}
