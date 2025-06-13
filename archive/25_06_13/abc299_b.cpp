// https://atcoder.jp/contests/abc299/tasks/abc299_b

#include<bits/stdc++.h>
using namespace std;
#define int ll

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T> constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vi c(n),r(n);
    cin >> c >> r;
    int cnt=0;
    int mx=0,ans;
    rep(i,n) {
        if (c[i]==t) {
            if (!cnt) {
                cnt=1;
                mx=0;
            }
            if (chmax(mx,r[i])) ans=i+1;
        } else if (!cnt && c[i]==c[0] && chmax(mx,r[i])) ans=i+1;
    }
    print(ans);

    return 0;
}
