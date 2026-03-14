// https://atcoder.jp/contests/abc449/tasks/abc449_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,l,r;
    string s;
    cin >> n >> l >> r >> s;
    vvi g(26);
    rep(i,n) g[s[i]-'a'].pb(i);
    int ans=0;
    for (vi a:g) {
        int m=a.size();
        if (m==0) continue;
        rep(i,m) {
            auto itl=lower_bound(all(a),a[i]+l);
            auto itr=upper_bound(all(a),a[i]+r);
            ans+=itr-itl;
        }
    }
    print(ans);

    return 0;
}
