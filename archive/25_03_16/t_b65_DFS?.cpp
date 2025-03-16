// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_el

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

vvi g;
vi d,ans;

int r(const int& pos) {
    d[pos]=1;
    int mx=-1;
    for(int val:g[pos]) {
        if(!d[val]) mx=max(mx,r(val));
    }
    return ans[pos]=mx+1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    g = vvi(n+1);
    int a,b;
    rep1(i,n-1) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    d = vi(n+1,0);
    ans = vi(n+1);
    r(t);
    rep1(i,n)cout<<(i-1?" ":"")<<ans[i];
    cout<<'\n';

    return 0;
}
