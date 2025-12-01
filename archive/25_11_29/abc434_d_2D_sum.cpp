// https://atcoder.jp/contests/abc434/tasks/abc434_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // 雲の分厚さの累積和
    vvi sm(2002,vi(2002,0));
    v<tuple<int,int,int,int>> t(n);
    for (auto&[u,d,l,r]:t) {
        cin >> u >> d >> l >> r;
        ++sm[u][l];
        --sm[u][r+1];
        --sm[d+1][l];
        ++sm[d+1][r+1];
    }
    // 雲の分厚さが1であるマスの個数の累積和
    vvi sm1(2001,vi(2001,0));
    int z=0;
    rep1(i,2e3)rep1(j,2e3) {
        sm[i][j]+=sm[i][j-1]+sm[i-1][j]-sm[i-1][j-1];
        if (sm[i][j]==1) ++sm1[i][j];
        if (sm[i][j]==0) ++z;
        sm1[i][j]+=sm1[i][j-1]+sm1[i-1][j]-sm1[i-1][j-1];
    }
    for (const auto&[u,d,l,r]:t) {
        int del=sm1[d][r]-sm1[d][l-1]-sm1[u-1][r]+sm1[u-1][l-1];
        print(z+del);
    }

    return 0;
}
