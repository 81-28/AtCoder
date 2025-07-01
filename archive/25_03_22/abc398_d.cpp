// https://atcoder.jp/contests/abc398/tasks/abc398_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define f first
#define s second
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    pii p;
    string st;
    cin >> n >> p >> st;
    map<int,map<int,bool>> t;
    pii b={0,0};
    t[b.f][b.s]=1;
    rep(i,n) {
        if (st[i]=='N') b.f++;
        if (st[i]=='W') b.s++;
        if (st[i]=='S') b.f--;
        if (st[i]=='E') b.s--;
        cout<<t[b.f+p.f][b.s+p.s];
        t[b.f][b.s]=1;
    }
    cout<<'\n';

    return 0;
}
