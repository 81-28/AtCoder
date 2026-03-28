// https://atcoder.jp/contests/abc451/tasks/abc451_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi ans(m,0);
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        --ans[a-1];
        ++ans[b-1];
    }
    rep(i,m) print(ans[i]);

    return 0;
}
