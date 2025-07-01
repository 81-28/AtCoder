// https://atcoder.jp/contests/abc405/tasks/abc405_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define f first
#define s second
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h),t;
    cin >> st;
    t=st;
    v<pii> e;
    v<v<bool>> a(h,v<bool>(w,0));
    rep(i,h)rep(j,w) {
        if (st[i][j]=='E') e.pb({i,j});
        if (st[i][j]=='.') a[i][j]=1;
    }
    queue<pii> q;
    rep(k,e.size()) {
        a[e[k].f][e[k].s]=0;
        q.push(e[k]);
    }
    pii pos;
    while (!q.empty()) {
        pos=q.front();
        q.pop();
        if (pos.f&&a[pos.f-1][pos.s]) {
            t[pos.f-1][pos.s]='v';
            a[pos.f-1][pos.s]=0;
            q.push({pos.f-1,pos.s});
        }
        if (pos.f<h-1&&a[pos.f+1][pos.s]) {
            t[pos.f+1][pos.s]='^';
            a[pos.f+1][pos.s]=0;
            q.push({pos.f+1,pos.s});
        }
        if (pos.s&&a[pos.f][pos.s-1]) {
            t[pos.f][pos.s-1]='>';
            a[pos.f][pos.s-1]=0;
            q.push({pos.f,pos.s-1});
        }
        if (pos.s<w-1&&a[pos.f][pos.s+1]) {
            t[pos.f][pos.s+1]='<';
            a[pos.f][pos.s+1]=0;
            q.push({pos.f,pos.s+1});
        }
    }
    rep(i,h)print(t[i]);

    return 0;
}
