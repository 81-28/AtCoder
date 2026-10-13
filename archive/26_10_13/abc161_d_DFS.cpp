// https://atcoder.jp/contests/abc161/tasks/abc161_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi l;
void dfs(int n) {
    int m=to_string(n).size();
    l.pb(n);
    if (m>9) return;
    int t=n%10;
    for (int i=max(t-1,0LL); i<=min(t+1,9LL); ++i) 
        dfs(n*10+i);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    rep1(i,9) dfs(i);
    sort(all(l));

    int k;
    cin >> k;
    print(l[--k]);
    
    return 0;
}
