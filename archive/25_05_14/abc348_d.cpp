// https://atcoder.jp/contests/abc348/tasks/abc348_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{1,0},{0,-1},{0,1}};

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}

template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> a(h);
    cin >> a;
    pii st,gl;
    rep(i,h)rep(j,w) {
        if (a[i][j]=='S') st={i,j};
        if (a[i][j]=='T') gl={i,j};
    }
    int n;
    cin >> n;
    map<pii,int> mp;
    pii p;
    int e;
    rep(i,n) {
        cin >> p >> e;
        --p;
        mp[p]=e;
    }
    vvi d(h,vi(w,-1));
    queue<pii> q;
    d[st.f][st.s]=0;
    q.push(st);
    pii pos,np;
    while (!q.empty()) {
        pos=q.front();
        q.pop();
        chmax(d[pos.f][pos.s],mp[pos]);
        e=d[pos.f][pos.s];
        if (e<1) continue;
        rep(i,4) {
            np=pos+dir[i];
            if ((0<=np.f&&np.f<h&&0<=np.s&&np.s<w) && a[np.f][np.s]!='#') {
                if (chmax(d[np.f][np.s],e-1)) q.push(np);
            }
        }
    }
    YesNo(d[gl.f][gl.s]>=0);

    return 0;
}
