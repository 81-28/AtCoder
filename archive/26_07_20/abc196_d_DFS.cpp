// https://atcoder.jp/contests/abc196/tasks/abc196_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int h,w;
vvb g;
int dfs(int n,int a,int b) {
    if (n==h*w) return 1;
    int i=n/w,j=n%w;
    if (g[i][j]) return dfs(n+1,a,b);
    int res=0;
    if (a) {
        if (i+1<h) {
            g[i+1][j]=1;
            res+=dfs(n+1,a-1,b);
            g[i+1][j]=0;
        }
        if (j+1<w && !g[i][j+1]) res+=dfs(n+2,a-1,b);
    }
    if (b) res+=dfs(n+1,a,b-1);
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int a,b;
    cin >> h >> w >> a >> b;
    g=vvb(h,vb(w,0));
    print(dfs(0,a,b));

    return 0;
}
