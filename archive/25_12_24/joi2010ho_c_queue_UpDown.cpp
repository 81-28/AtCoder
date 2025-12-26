// https://atcoder.jp/contests/joi2010ho/tasks/joi2010ho_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,l;
    cin >> n >> l;
    vi a(n);
    cin >> a;
    vvi g(n);
    queue<int> q;
    vi cnt(n);
    rep(i,n) {
        int par=0;
        if (i) {
            if (a[i]>a[i-1]) g[i].pb(i-1);
            else ++par;
        }
        if (i+1<n) {
            if (a[i]>a[i+1]) g[i].pb(i+1);
            else ++par;
        }
        if (!par) q.push(i);
        cnt[i]=par;
    }
    // 極大値から下って答えを順に求める
    vi ans(n,0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        int mx=0;
        if (pos) chmax(mx,ans[pos-1]);
        if (pos+1<n) chmax(mx,ans[pos+1]);
        ans[pos]=mx+l-a[pos];
        for (int nxt:g[pos]) {
            if (!--cnt[nxt]) q.push(nxt);
        }
    }
    print(max(ans));

    return 0;
}
