// https://atcoder.jp/contests/abc434/tasks/abc434_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(m);
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        --a;
        g[a].pb(b);
    }
    cout<<fixed<<setprecision(16);
    for (vi vec:g) {
        print(sum(vec)/(double)(vec.size()));
    }

    return 0;
}
