// https://atcoder.jp/contests/abc400/tasks/abc400_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define f first
#define s second
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> ss(h);
    cin >> ss;
    pii st,gl;
    cin >> st >> gl;
    --st.f,--st.s,--gl.f,--gl.s;
    vvi d(h,vi(w,h+w));
    pii p,np;
    int dist;
    deque<pii> q;
    d[st.f][st.s]=0;
    q.push_back(st);
    while (!q.empty()) {
        p=q.front();
        q.pop_front();
        dist=d[p.f][p.s];
        rep(i,4) {
            np={p.f+dx[i],p.s+dy[i]};
            if ((0<=np.f&&np.f<h&&0<=np.s&&np.s<w) && ss[np.f][np.s]=='.' && d[np.f][np.s]>dist) {
                d[np.f][np.s]=dist;
                q.push_front(np);
            }
            rep1(j,2) {
                np={p.f+j*dx[i],p.s+j*dy[i]};
                if ((0<=np.f&&np.f<h&&0<=np.s&&np.s<w) && d[np.f][np.s]>dist+1) {
                    d[np.f][np.s]=dist+1;
                    q.push_back(np);
                }
            }
        }
    }
    print(d[gl.f][gl.s]);

    return 0;
}
