// https://atcoder.jp/contests/abc480/tasks/abc480_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    int k=sum(a)/m;
    int mx=1<<n;
    // 状態i:iの立っているビットのケーキのみを選んだ状態
    // dp[i]:状態iのとき、丁度kの倍数の位置に来るケーキの区切りの数の、
    // （あらゆる並べ順を考慮した）最大値
    vi dp(mx,0);
    // sm[i]:状態iのケーキの大きさ合計
    vi sm(mx,0);
    // 昇順に拾うDPをするので、実行順はok
    rep1(i,mx-1) {
        rep(j,n) {
            if (!((i>>j)&1)) continue;
            int pre=i^(1<<j);
            sm[i]=sm[pre]+a[j];
            chmax(dp[i],dp[pre]+(sm[i]%k==0));
        }
    }
    print(m-dp[mx-1]);

    return 0;
}
