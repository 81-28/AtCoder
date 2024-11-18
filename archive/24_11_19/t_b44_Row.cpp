// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dq

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q,m,x,y,tmp;
    cin >> n;
    vvi a(n,vi(n));
    rep(i,n) cin >> a[i];
    vi r(n+1);
    rep1(i,n) r[i]=i;

    cin >> q;
    rep(k,q) {
        cin >> m >> x >> y;
        if(m==1) {
            tmp = r[x];
            r[x] = r[y];
            r[y] = tmp;
        }
        if(m==2) print(a[r[x]-1][y-1]);
    }

    return 0;
}
