// https://atcoder.jp/contests/abc460/tasks/abc460_d

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)


#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    // INF:未確定
    vvi b(h,vi(w,INF));
    queue<pii> q;
    rep(i,h)rep(j,w) {
        pii pos={i,j};
        // '#'の個数,周りのマス数
        int cnt=0,al=0;
        rep(k,8) {
            pii nxt=pos+dir[k];
            if (OutOfGrid(nxt,{h,w})) continue;
            ++al;
            cnt+=st[nxt.f][nxt.s]=='#';
        }
        bool b0=st[i][j]=='#';
        // 周囲に自身と異なる色が1つでもあれば、点滅が確定する
        if (cnt!=al*b0) {
            b[i][j]=!b0;
            q.push({i,j});
        }
        // 周囲が全て自身と同じ色だったら、確定しない
        // その場合、1手後からは白になり、周囲に初めて黒が来た次の手で黒となる
    }
    // 確定を伝播させる
    while (!q.empty()) {
        pii pos=q.front();
        q.pop();
        bool bb=b[pos.f][pos.s];
        rep(k,8) {
            pii nxt=pos+dir[k];
            if (OutOfGrid(nxt,{h,w})) continue;
            if (b[nxt.f][nxt.s]!=INF) continue;
            b[nxt.f][nxt.s]=!bb;
            q.push(nxt);
        }
    }
    rep(i,h) {
        rep(j,w) cout<<(b[i][j]?'.':'#');
        cout<<endl;
    }

    return 0;
}
