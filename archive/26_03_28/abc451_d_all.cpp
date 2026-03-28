// https://atcoder.jp/contests/abc451/tasks/abc451_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi ten;
// num[i]:長さがiの2の冪
vvi num;
// d[i]:dfs(i)の結果
map<int,vi> d;
// 長さnの良い整数の集合
vi dfs(int n) {
    if (n==0) return vi(1,0);
    if (d.find(n)!=d.end()) return d[n];
    vi res;
    // 新規i + 既存(n-i) の長さで生成
    rep1(i,n) {
        vi h=num[i];
        vi t=dfs(n-i);
        for (int vh:h) for (int vt:t) {
            res.pb(vh*ten[n-i]+vt);
        }
    }
    sort(all(res));
    uniq(res);
    return d[n]=res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ten=vi(10);
    ten[0]=1;
    rep1(i,9) ten[i]=ten[i-1]*10;

    num=vvi(10);
    for (int i=1; i<=ten[9]; i*=2) num[to_string(i).size()].pb(i);
    // 長さがiの良い整数を作成
    vi g;
    rep1(i,9) {
        vi vec=dfs(i);
        for (int val:vec) g.pb(val);
    }
    sort(all(g));
    uniq(g);

    int n;
    cin >> n;
    print(g[n-1]);

    return 0;
}
