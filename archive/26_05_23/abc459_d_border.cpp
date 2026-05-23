// https://atcoder.jp/contests/abc459/tasks/abc459_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n=s.size();
        vi cnt(26,0);
        for (char c:s) ++cnt[c-'a'];
        // {数,番号}
        v<pii> p(26);
        rep(i,26) p[i]={cnt[i],i};
        sort(rall(p));
        int mx=p[0].first;
        if (mx>(n+1)/2) {
            YesNo(0);
            continue;
        }

        string st="";
        rep(i,26) {
            rep(j,p[i].first) st.pb(char(p[i].second+'a'));
        }
        string ans=s;
        int idx=0;
        rep(i,n) {
            if (i&1) continue;
            ans[i]=st[idx++];
        }
        rep(i,n) {
            if (!(i&1)) continue;
            ans[i]=st[idx++];
        }
        YesNo(1);
        print(ans);
    }

    return 0;
}
