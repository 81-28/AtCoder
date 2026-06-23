// https://atcoder.jp/contests/abc213/tasks/abc213_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()


vvi g;
vb b;
void dfs(int n) {
    cout<<n<<' ';
    for (int nxt:g[n]) {
        if (b[nxt]) continue;
        b[nxt]=1;
        dfs(nxt);
        cout<<n<<' ';
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    g=vvi(n+1);
    rep1(i,n-1) {
        int a,c;
        cin >> a >> c;
        g[a].pb(c);
        g[c].pb(a);
    }
    rep1(i,n) sort(all(g[i]));
    b=vb(n+1,0);
    b[1]=1;
    dfs(1);
    cout<<endl;

    return 0;
}
