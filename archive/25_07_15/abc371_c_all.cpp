// https://atcoder.jp/contests/abc371/tasks/abc371_c

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

template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int mg;
    cin >> mg;
    v<map<int,bool>> g(n);
    rep(i,mg) {
        pii p;
        cin >> p;
        --p;
        g[p.f][p.s]=g[p.s][p.f]=1;
    }
    int mh;
    cin >> mh;
    v<map<int,bool>> h(n);
    rep(i,mh) {
        pii p;
        cin >> p;
        --p;
        h[p.f][p.s]=h[p.s][p.f]=1;
    }
    map<pii,int> a;
    rep(i,n-1)for(int j=i+1; j<n; ++j) {
        int c;
        cin >> c;
        a[{i,j}]=a[{j,i}]=c;
    }
    vi vec(n);
    rep(i,n) vec[i]=i;
    int ans=INT_MAX;
    do {
        int sm=0;
        rep(i,n-1)for(int j=i+1; j<n; ++j) {
            if (g[i][j]!=h[vec[i]][vec[j]]) sm+=a[{vec[i],vec[j]}];
        }
        chmin(ans,sm);
    } while (next_permutation(all(vec)));
    print(ans);

    return 0;
}
