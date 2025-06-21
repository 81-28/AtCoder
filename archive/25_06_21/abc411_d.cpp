// https://atcoder.jp/contests/abc411/tasks/abc411_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<pair<pii,string>> qu(q);
    rep(i,q) {
        cin >> qu[i].f;
        if (qu[i].f.f==2) cin >> qu[i].s;
    }
    int idx=-1;
    v<string> st;
    for (int i=q-1; i>=0; --i) {
        if (qu[i].f.f==1 && qu[i].f.s==idx) idx=-1;
        if (qu[i].f.f==2 && qu[i].f.s==idx) st.pb(qu[i].s);
        if (qu[i].f.f==3 && idx==-1) idx=qu[i].f.s;
    }
    for (int i=st.size()-1; i>=0; --i) cout<<st[i];
    cout<<endl;

    return 0;
}
