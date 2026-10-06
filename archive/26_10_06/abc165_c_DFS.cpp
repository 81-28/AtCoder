// https://atcoder.jp/contests/abc165/tasks/abc165_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vvi t;
int score(vi& a) {
    int res=0;
    for (vi s:t) {
        if (a[s[1]]-a[s[0]]==s[2]) res+=s[3];    
    }
    return res;
}

int n,m;
int dfs(vi& a,int i) {
    if (i==n) return score(a);
    int res=0;
    int b=1;
    if (i) b=a[i-1];
    for (int j=b; j<=m; ++j) {
        a[i]=j;
        chmax(res,dfs(a,i+1));
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> n >> m >> q;
    t=vvi(q,vi(4));
    rep(i,q) {
        cin >> t[i];
        --t[i][0],--t[i][1];
    }
    vi a(n);
    print(dfs(a,0));

    return 0;
}
