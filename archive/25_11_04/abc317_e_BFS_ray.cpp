// https://atcoder.jp/contests/abc317/tasks/abc317_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[5]={{-1,0},{0,-1},{1,0},{0,1},{0,0}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S> pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairの加算代入 (+=)
template<typename F,typename S> pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


constexpr int inf=INT_MAX;

bool in(const pii& p,const int& h,const int& w) {
    const auto&[i,j]=p;
    return (0<=i&&i<h && 0<=j&&j<w);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<char,int> di;
    di['^']=0;
    di['<']=1;
    di['v']=2;
    di['>']=3;
    di['#']=4;

    int h,w;
    cin >> h >> w;
    v<string> a(h);
    cin >> a;
    pii st,go;
    v<v<bool>> b(h,v<bool>(w,0));
    rep(i,h)rep(j,w) {
        if (a[i][j]=='S') st={i,j};
        else if (a[i][j]=='G') go={i,j};
        else if (a[i][j]!='.') {
            b[i][j]=1;
            pii pos={i,j};
            for (pos+=dir[di[a[i][j]]];in(pos,h,w);pos+=dir[di[a[i][j]]]) {
                if (a[pos.f][pos.s]!='.') break;
                b[pos.f][pos.s]=1;
            }
        }
    }
    vvi d(h,vi(w,inf));
    queue<pii> q;
    d[st.f][st.s]=0;
    q.push(st);
    while (!q.empty()) {
        pii pos=q.front();
        q.pop();
        int dist=d[pos.f][pos.s];
        rep(k,4) {
            auto[i,j]=pos+dir[k];
            if (!in({i,j},h,w) || b[i][j]) continue;
            if (chmin(d[i][j],dist+1)) q.push({i,j});
        }
        if (d[go.f][go.s]!=inf) {
            print(d[go.f][go.s]);
            return 0;
        }
    }
    print(-1);

    return 0;
}
