// https://atcoder.jp/contests/abc319/tasks/abc319_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi fact(10);

vvi c(3,vi(3));
v<v<bool>> b(3,v<bool>(3,0));
// a:残りの数
int dfs(const vi& a) {
    int res=0;
    int n=a.size();
    rep(i,n) {
        int x=a[i]/3,y=a[i]%3;
        b[x][y]=1;
        int u=(x+2)%3,d=(x+1)%3;
        int l=(y+2)%3,r=(y+1)%3;
        bool ok=1;
        if (b[u][y] && b[d][y] && c[u][y]==c[d][y]) ok=0;
        if (b[x][l] && b[x][r] && c[x][l]==c[x][r]) ok=0;
        if (x==y && b[u][l] && b[d][r] && c[u][l]==c[d][r]) ok=0;
        if (x+y==2 && b[u][r] && b[d][l] && c[u][r]==c[d][l]) ok=0;
        if (ok) {
            vi aa=a;
            aa.erase(aa.begin()+i);
            res+=dfs(aa);
        } else res+=fact[n-1];
        b[x][y]=0;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> c;
    fact[0]=1;
    rep1(i,9) fact[i]=fact[i-1]*i;
    cout<<fixed<<setprecision(16);
    vi a(9);
    rep(i,9) a[i]=i;
    print(1-(double)dfs(a)/fact[9]);

    return 0;
}
