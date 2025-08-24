// https://atcoder.jp/contests/abc420/tasks/abc420_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> a(h);
    cin >> a;
    v<string> b=a;
    pii st,go;
    rep(i,h)rep(j,w) {
        if (a[i][j]=='S') st={i,j};
        if (a[i][j]=='G') go={i,j};
        if (a[i][j]=='x') a[i][j]='#';
        if (b[i][j]=='o') b[i][j]='#';
    }
    v<v<string>> c(2);
    c[0]=a,c[1]=b;
    const int inf=INT_MAX;
    v<vvi> d(2,vvi(h,vi(w,inf)));
    // {表裏,i,j}
    queue<tuple<bool,int,int>> q;
    q.push({0,st.f,st.s});
    d[0][st.f][st.s]=0;
    while (!q.empty()) {
        auto[b,x,y]=q.front();
        q.pop();
        if (x-1>=0) {
            if (c[b][x-1][y]=='?') {
                if (d[!b][x-1][y]==inf) {
                    d[!b][x-1][y]=d[b][x][y]+1;
                    q.push({!b,x-1,y});
                }
            } else if (c[b][x-1][y]!='#' && d[b][x-1][y]==inf) {
                d[b][x-1][y]=d[b][x][y]+1;
                q.push({b,x-1,y});
            }
        }
        if (y-1>=0) {
            if (c[b][x][y-1]=='?') {
                if (d[!b][x][y-1]==inf) {
                    d[!b][x][y-1]=d[b][x][y]+1;
                    q.push({!b,x,y-1});
                }
            } else if (c[b][x][y-1]!='#' && d[b][x][y-1]==inf) {
                d[b][x][y-1]=d[b][x][y]+1;
                q.push({b,x,y-1});
            }
        }
        if (x+1<h) {
            if (c[b][x+1][y]=='?') {
                if (d[!b][x+1][y]==inf) {
                    d[!b][x+1][y]=d[b][x][y]+1;
                    q.push({!b,x+1,y});
                }
            } else if (c[b][x+1][y]!='#' && d[b][x+1][y]==inf) {
                d[b][x+1][y]=d[b][x][y]+1;
                q.push({b,x+1,y});
            }
        }
        if (y+1<w) {
            if (c[b][x][y+1]=='?') {
                if (d[!b][x][y+1]==inf) {
                    d[!b][x][y+1]=d[b][x][y]+1;
                    q.push({!b,x,y+1});
                }
            } else if (c[b][x][y+1]!='#' && d[b][x][y+1]==inf) {
                d[b][x][y+1]=d[b][x][y]+1;
                q.push({b,x,y+1});
            }
        }
        if (d[0][go.f][go.s]!=inf) {
            print(d[0][go.f][go.s]);
            return 0;
        }
        if (d[1][go.f][go.s]!=inf) {
            print(d[1][go.f][go.s]);
            return 0;
        }
    }
    print(-1);

    return 0;
}
