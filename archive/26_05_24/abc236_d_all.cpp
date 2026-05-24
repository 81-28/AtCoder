// https://atcoder.jp/contests/abc236/tasks/abc236_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


vvi a;
// vecを用いて作られる答えの集合
vi f(const vi& vec) {
    int l=vec.size();
    if (l==0) return {0};
    vi res;
    rep1(i,l-1) {
        vi nxv;
        rep1(j,l-1) {
            if (j==i) continue;
            nxv.pb(vec[j]);
        }
        vi nxf=f(nxv);
        for (int val:nxf) res.pb(val^a[vec[0]][vec[i]]);
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    n*=2;
    a=vvi(n,vi(n,0));
    rep(i,n-1)for(int j=i+1; j<n; ++j) cin >> a[i][j];
    vi b(n);
    rep(i,n) b[i]=i;
    vi ans=f(b);
    print(max(ans));

    return 0;
}
