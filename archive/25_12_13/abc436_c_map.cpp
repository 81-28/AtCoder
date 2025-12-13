// https://atcoder.jp/contests/abc436/tasks/abc436_c

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    unordered_map<int,unordered_map<int,bool>> mp;
    int ans=0;
    while (m--) {
        int r,c;
        cin >> r >> c;
        bool ok=1;
        if (mp[r][c]) ok=0;
        if (mp[r][c+1]) ok=0;
        if (mp[r+1][c]) ok=0;
        if (mp[r+1][c+1]) ok=0;
        if (!ok) continue;
        mp[r][c]=mp[r][c+1]=mp[r+1][c]=mp[r+1][c+1]=1;
        ++ans;
    }
    print(ans);

    return 0;
}
