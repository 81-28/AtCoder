// https://atcoder.jp/contests/abc378/tasks/abc378_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}


int h,w;
v<string> a;
v<v<bool>> b;
ll ans=0;
void dfs(const pii& p,const int& k) {
    if (a[p.f][p.s]=='#') return;
    if (k==0) ++ans;
    else {
        b[p.f][p.s]=1;
        rep(i,4) {
            pii np=p+dir[i];
            if ((0<=np.f&&np.f<h&&0<=np.s&&np.s<w) && !b[np.f][np.s]) {
                dfs(np,k-1);
            }
        }
        b[p.f][p.s]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int k;
    cin >> h >> w >> k;
    a=v<string>(h);
    cin >> a;
    b=v<v<bool>>(h,v<bool>(w,0));
    rep(i,h)rep(j,w) dfs({i,j},k);
    print(ans);

    return 0;
}
