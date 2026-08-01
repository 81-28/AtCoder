// https://atcoder.jp/contests/abc469/tasks/abc469_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vb d(n+1,0);
    int a,b;
    cin >> a >> b;
    d[a]=d[b]=1;
    v<set<int>> st(2);
    rep1(i,n) rep(j,2) st[j].insert(i);
    st[0].erase(a);
    st[1].erase(b);
    while (--m) {
        int aa,bb;
        cin >> aa >> bb;
        unordered_map<int,bool> mp;
        mp[aa]=mp[bb]=1;
        rep(i,2) {
            if (i==0 && mp[a]) continue;
            if (i==1 && mp[b]) continue;
            vb dd(2,0);
            if (st[i].find(aa)!=st[i].end()) dd[0]=1;
            if (st[i].find(bb)!=st[i].end()) dd[1]=1;
            st[i].clear();
            if (dd[0]) st[i].insert(aa);
            if (dd[1]) st[i].insert(bb);
        }
    }
    int ans=st[0].size()+st[1].size();
    if (st[0].find(b)!=st[0].end()) --ans;
    print(ans);

    return 0;
}
