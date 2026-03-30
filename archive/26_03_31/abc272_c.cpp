// https://atcoder.jp/contests/abc272/tasks/abc272_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(2);
    rep(i,n) {
        int aa;
        cin >> aa;
        a[aa&1].pb(aa);
    }
    int ans=-1;
    rep(i,2) {
        sort(rall(a[i]));
        if (a[i].size()<2) continue;
        chmax(ans,a[i][0]+a[i][1]);
    }
    print(ans);

    return 0;
}
