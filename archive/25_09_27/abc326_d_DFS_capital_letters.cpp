// https://atcoder.jp/contests/abc326/tasks/abc326_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


int n;
string r,c;
v<v<map<char,int>>> cnt;
v<string> ans;
bool dfs(const int& m) {
    if (m==n*n) return 1;
    int x=m/n,y=m%n;
    if (cnt[0][x]['.']&&cnt[1][y]['.']) {
        --cnt[0][x]['.'],--cnt[1][y]['.'];
        if (dfs(m+1)) {
            ans[x][y]='.';
            return 1;
        }
        ++cnt[0][x]['.'],++cnt[1][y]['.'];
    }
    bool h,t;
    if (cnt[0][x]['A']&&cnt[1][y]['A'] && (r[x]=='A'||r[x]=='.')&&(c[y]=='A'||c[y]=='.')) {
        --cnt[0][x]['A'],--cnt[1][y]['A'];
        h=r[x]=='A';
        t=c[y]=='A';
        r[x]='.';
        c[y]='.';
        if (dfs(m+1)) {
            ans[x][y]='A';
            return 1;
        }
        if (h) r[x]='A';
        if (t) c[y]='A';
        ++cnt[0][x]['A'],++cnt[1][y]['A'];
    }
    if (cnt[0][x]['B']&&cnt[1][y]['B'] && (r[x]=='B'||r[x]=='.')&&(c[y]=='B'||c[y]=='.')) {
        --cnt[0][x]['B'],--cnt[1][y]['B'];
        h=r[x]=='B';
        t=c[y]=='B';
        r[x]='.';
        c[y]='.';
        if (dfs(m+1)) {
            ans[x][y]='B';
            return 1;
        }
        if (h) r[x]='B';
        if (t) c[y]='B';
        ++cnt[0][x]['B'],++cnt[1][y]['B'];
    }
    if (cnt[0][x]['C']&&cnt[1][y]['C'] && (r[x]=='C'||r[x]=='.')&&(c[y]=='C'||c[y]=='.')) {
        --cnt[0][x]['C'],--cnt[1][y]['C'];
        h=r[x]=='C';
        t=c[y]=='C';
        r[x]='.';
        c[y]='.';
        if (dfs(m+1)) {
            ans[x][y]='C';
            return 1;
        }
        if (h) r[x]='C';
        if (t) c[y]='C';
        ++cnt[0][x]['C'],++cnt[1][y]['C'];
    }
    return 0;
}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> r >> c;
    cnt=v<v<map<char,int>>>(2,v<map<char,int>>(n));
    rep(i,2)rep(j,n) {
        cnt[i][j]['A']=1;
        cnt[i][j]['B']=1;
        cnt[i][j]['C']=1;
        cnt[i][j]['.']=n-3;
    }
    ans=v<string>(n,string(n,'.'));
    if (dfs(0)) {
        YesNo(1);
        rep(i,n) print(ans[i]);
    } else YesNo(0);

    return 0;
}
