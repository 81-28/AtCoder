// https://atcoder.jp/contests/abc447/tasks/abc447_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    string ss="",tt="";
    for (char c:s) {
        if (c=='A') continue;
        ss+=c;
    }
    for (char c:t) {
        if (c=='A') continue;
        tt+=c;
    }
    if (ss!=tt) {
        print(-1);
        return 0;
    }
    vi a;
    int cmb=0;
    for (char c:s) {
        if (c=='A') {
            ++cmb;
        } else {
            a.pb(cmb);
            cmb=0;
        }
    }
    a.pb(cmb);
    vi b;
    cmb=0;
    for (char c:t) {
        if (c=='A') {
            ++cmb;
        } else {
            b.pb(cmb);
            cmb=0;
        }
    }
    b.pb(cmb);
    int l=a.size();
    int ans=0;
    rep(i,l) {
        ans+=abs(a[i]-b[i]);
    }
    print(ans);

    return 0;
}
