// https://atcoder.jp/contests/abc407/tasks/abc407_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T> constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int h,w;
vvll a;
v<v<bool>> b;
ll ans=0,x=0;
void dfs(const int& n) {
    if (n==h*w-1) chmax(ans,x);
    else {
        dfs(n+1);
        int i=n/w,j=n%w;
        if (!b[i][j]) {
            if (i+1<h && !b[i+1][j]) {
                b[i][j]=1,b[i+1][j]=1;
                x^=a[i][j],x^=a[i+1][j];
                dfs(n+1);
                b[i][j]=0,b[i+1][j]=0;
                x^=a[i][j],x^=a[i+1][j];
            }
            if (j+1<w && !b[i][j+1]) {
                b[i][j]=1,b[i][j+1]=1;
                x^=a[i][j],x^=a[i][j+1];
                dfs(n+1);
                b[i][j]=0,b[i][j+1]=0;
                x^=a[i][j],x^=a[i][j+1];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> h >> w;
    a = vvll(h,vll(w));
    cin >> a;
    rep(i,h)rep(j,w) x^=a[i][j];
    b = v<v<bool>>(h,v<bool>(w,0));
    dfs(0);
    print(ans);

    return 0;
}
