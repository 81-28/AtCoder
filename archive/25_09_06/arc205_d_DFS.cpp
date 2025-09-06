// https://atcoder.jp/contests/arc205/tasks/arc205_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// c[i]:iの子供たち
vvi c;
// {その頂点も含めた、子の数,操作回数}
pii dfs(const int& n) {
    int sm=0;
    int mx=-1;
    pii mp;
    int res=0;
    for (int nxt:c[n]) {
        pii q=dfs(nxt);
        sm+=q.f;
        if (chmax(mx,q.f)) mp=q;
    }
    if (sm-mx<mx) res=sm-mx+min((mx-(sm-mx))/2,mp.s);
    else res=sm/2;
    return {sm+1,res};
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        c=vvi(n+1);
        for (int i=2; i<=n; ++i) {
            int p;
            cin >> p;
            c[p].pb(i);
        }
        print(dfs(1).s);
    }

    return 0;
}
