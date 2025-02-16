// https://atcoder.jp/contests/abc323/tasks/abc323_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}
template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vll a(m);
    v<string> s(n);
    cin >> a >> s;
    vll c(n,0);
    vvll r(n);
    rep(i,n){
        c[i] += i+1;
        rep(j,m) {
            if (s[i][j] == 'o') c[i] += a[j];
            else r[i].pb(a[j]);
        }
        sort(rall(r[i]));
    }
    ll ma = max(c);
    ll ans;
    rep(i,n) {
        ans = 0;
        if (c[i] != ma) {
            for (int j=0; c[i]<ma; j++) {
                c[i] += r[i][j];
                ans++;
            }
        }
        print(ans);
    }

    return 0;
}
