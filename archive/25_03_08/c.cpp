// https://atcoder.jp/contests/abc396/tasks/abc396_c

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

    ll n,m;
    cin >> n >> m;
    vll b(n),w(m);
    cin >> b >> w;
    sort(rall(b));
    sort(rall(w));
    ll ans=0;
    ll p=0;
    rep(i,n) {
        if (b[i]>=0) {
            ans+=b[i];
            p++;
        } else break;
    }
    rep(i,m) {
        if (i >= p) {
            if (i<n && b[i] + w[i] >= 0) {
                ans+=b[i]+w[i];
            }
        } else if (w[i] >= 0) ans+=w[i];
        else break;
    }
    print(ans);


    return 0;
}
