// https://atcoder.jp/contests/abc437/tasks/abc437_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans=0,sm=0;
        vi a;
        rep(i,n) {
            int w,p;
            cin >> w >> p;
            sm+=p;
            a.pb(w+p);
        }
        sort(all(a));
        for (int val:a) {
            if (sm-val<0) break;
            sm-=val;
            ++ans;
        }
        print(ans);
    }

    return 0;
}
