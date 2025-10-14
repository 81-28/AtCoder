// https://atcoder.jp/contests/abc391/tasks/abc391_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


string st;
// {範囲[l,r)の値,反転するのに必要な変更最小数},p={l,r}
pair<bool,int> dfs(const pii& p) {
    auto[l,r]=p;
    if (l+1==r) return {st[l]=='1',1};
    int w=(r-l)/3;
    int cnt=0;
    // sm[i]:!iにするのに必要な変更数
    vvi sm(2);
    rep(i,3) {
        int nl=l+w*i,nr=nl+w;
        pii q=dfs({nl,nr});
        cnt+=q.f;
        sm[q.f].pb(q.s);
    }
    bool c=cnt/2;
    sort(all(sm[c]));
    int res=0;
    for (int i=0; c?(cnt-i>1):(cnt+i<2); ++i) res+=sm[c][i];
    return {c,res};
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n >> st;
    int m=int_pow(3,n);
    print(dfs({0,m}).s);

    return 0;
}
