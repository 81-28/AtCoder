// https://atcoder.jp/contests/abc436/tasks/abc436_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(n,vi(n,0));
    queue<pii> q;
    a[0][(n-1)/2]=1;
    q.push({0,(n-1)/2});
    while (!q.empty()) {
        auto[r,c]=q.front();
        q.pop();
        int k=a[r][c];
        r+=n-1,++c;
        r%=n,c%=n;
        if (a[r][c]!=0) {
            r+=2,c+=n-1;
            r%=n,c%=n;
        }
        if (a[r][c]!=0) break;
        a[r][c]=k+1;
        q.push({r,c});
    }
    rep(i,n) print(a[i]);

    return 0;
}
