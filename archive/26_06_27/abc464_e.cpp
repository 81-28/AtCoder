// https://atcoder.jp/contests/abc464/tasks/abc464_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int h,w,q;
    cin >> h >> w >> q;
    v<tuple<int,int,char>> t(q);
    for (auto&[r,c,x]:t) {
        cin >> r >> c >> x;
        --r,--c;
    }
    v<string> ans(h,string(w,'A'));
    vvb b(h,vb(w,0));
    for (int k=q-1; k>=0; --k) {
        auto[r,c,x]=t[k];
        for (int i=r; i>=0; --i) {
            if (b[i][c]) break;
            for (int j=c; j>=0; --j) {
                if (b[i][j]) break;
                b[i][j]=1;
                ans[i][j]=x;
            }
        }
    }
    rep(i,h) print(ans[i]);

    return 0;
}
