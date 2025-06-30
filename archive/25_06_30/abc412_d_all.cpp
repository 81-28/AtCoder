// https://atcoder.jp/contests/abc412/tasks/abc412_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<class T>constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<map<int,bool>> g(n);
    rep(i,m) {
        pii p;
        cin >> p;
        --p;
        g[p.f][p.s]=1;
        g[p.s][p.f]=1;
    }
    vi p(n);
    rep(i,n) p[i]=i;
    int ans=INT_MAX;
    do {
        int add=0;
        rep(i,n) {
            int j=(i+1)%n;
            if (!g[p[i]][p[j]]||!g[p[j]][p[i]]) ++add;
        }
        chmin(ans,m+add*2-n);
        for (int i=3; i<=n/2&&n-i>2; i++) {
            add=0;
            rep(j,n) {
                int k=j+1;
                if (k==i) k=0;
                if (k==n) k=i;
                if (!g[p[j]][p[k]]||!g[p[k]][p[j]]) ++add;
            }
            chmin(ans,m+add*2-n);
        }
    } while (next_permutation(all(p)));
    print(ans);

    return 0;
}
