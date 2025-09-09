// https://atcoder.jp/contests/abc363/tasks/abc363_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,y;
    cin >> h >> w >> y;
    // 海に接しているマスの{高さ,{i,j}}
    priority_queue<pair<int,pii>,v<pair<int,pii>>,greater<>> pq;
    // pqに追加済みかどうか
    v<v<bool>> b(h,v<bool>(w,0));
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) {
        cin >> a[i][j];
        if (i==0||j==0||i+1==h||j+1==w) {
            pq.push({a[i][j],{i,j}});
            b[i][j]=1;
        }
    }
    int ans=h*w;
    rep1(k,y) {
        while (!pq.empty()) {
            auto[l,p]=pq.top();
            if (l>k) break;
            pq.pop();
            --ans;
            rep(m,4) {
                auto[i,j]=p+dir[m];
                if (0<=i&&i<h && 0<=j&&j<w && !b[i][j]) {
                    pq.push({a[i][j],{i,j}});
                    b[i][j]=1;
                }
            }
        }
        print(ans);
    }

    return 0;
}
