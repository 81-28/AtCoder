// https://atcoder.jp/contests/abc433/tasks/abc433_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    // {数,長さ}
    v<pii> l(n),r(n);
    l[0]={s[0]-'0',1};
    for (int i=1; i<n; ++i) {
        auto[num,len]=l[i-1];
        int m=s[i]-'0';
        if (m==num) l[i]={m,len+1};
        else l[i]={m,1};
    }
    r[n-1]={s[n-1]-'0',1};
    for (int i=n-2; i>=0; --i) {
        auto[num,len]=r[i+1];
        int m=s[i]-'0';
        if (m==num) r[i]={m,len+1};
        else r[i]={m,1};
    }
    int ans=0;
    rep(i,n-1) {
        auto[nl,sl]=l[i];
        auto[nr,sr]=r[i+1];
        if (nl+1==nr) ans+=min(sl,sr);
    }
    print(ans);

    return 0;
}
