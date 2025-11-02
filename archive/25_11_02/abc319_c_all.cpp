// https://atcoder.jp/contests/abc319/tasks/abc319_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vvi c(3,vi(3));
    cin >> c;
    vi a(9);
    rep(i,9) a[i]=i;
    int ans=0,sm=0;
    do {
        v<v<bool>> b(3,v<bool>(3,0));
        bool ok=1;
        for (int n:a) {
            int x=n/3,y=n%3;
            b[x][y]=1;
            int u=(x+2)%3,d=(x+1)%3;
            int l=(y+2)%3,r=(y+1)%3;
            if (b[u][y] && b[d][y] && c[u][y]==c[d][y]) ok=0;
            if (b[x][l] && b[x][r] && c[x][l]==c[x][r]) ok=0;
            if (x==y && b[u][l] && b[d][r] && c[u][l]==c[d][r]) ok=0;
            if (x+y==2 && b[u][r] && b[d][l] && c[u][r]==c[d][l]) ok=0;
            if (!ok) break;
        }
        if (ok) ++ans;
        ++sm;
    } while (next_permutation(all(a)));
    cout<<fixed<<setprecision(16);
    print((double)ans/sm);

    return 0;
}
