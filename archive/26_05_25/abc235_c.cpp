// https://atcoder.jp/contests/abc235/tasks/abc235_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    map<int,vi> m;
    rep1(i,n) {
        int a;
        cin >> a;
        m[a].pb(i);
    }
    while (q--) {
        int x,k;
        cin >> x >> k;
        print(--k<m[x].size()?m[x][k]:-1);
    }

    return 0;
}
