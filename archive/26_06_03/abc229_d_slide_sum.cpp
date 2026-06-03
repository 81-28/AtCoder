// https://atcoder.jp/contests/abc229/tasks/abc229_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;
    int n=s.size();
    // sm[i]:i番目までの'.'の個数
    vi sm(n+1,0);
    rep(i,n) sm[i+1]=sm[i]+(s[i]=='.');
    int r=1,ans=0;
    rep(l,n) {
        while (r<n && sm[r+1]-sm[l]<=k) ++r;
        chmax(ans,r-l);
    }
    print(ans);

    return 0;
}
