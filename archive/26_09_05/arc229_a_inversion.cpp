// https://atcoder.jp/contests/arc229/tasks/arc229_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x;
    cin >> x;
    if (!x) {
        cout<<'A';
        return 0;
    }
    int a=25;
    int d=a*a-x;
    int h=a-1,t=0;
    for (; d>=a; d-=a) {
        ++t,--h;
    }
    string ans="";
    vb c(a+1,0);
    c[d]=1;
    rep(i,h) ans.pb('A');
    rep(i,a+1) ans.pb(c[i]?'A':'C');
    rep(i,t) ans.pb('A');
    int l=ans.size();
    cout<<ans[0];
    rep(i,l-1) cout<<'R'<<ans[i+1];

    return 0;
}
