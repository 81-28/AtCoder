// https://atcoder.jp/contests/abc332/tasks/abc332_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


constexpr int inf=INT_MAX;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    vvi a(h,vi(w)),b=a;
    cin >> a >> b;
    vi idx(h),jdx(w);
    rep(i,h) idx[i]=i;
    rep(j,w) jdx[j]=j;
    int ans=inf;
    do {
        do {
            bool ok=1;
            rep(i,h) {
                rep(j,w) {
                    if (a[idx[i]][jdx[j]]!=b[i][j]) {
                        ok=0;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                int sm=0;
                rep(i,h-1)for (int j=i+1; j<h; ++j) {
                    if (idx[i]>idx[j]) ++sm;
                }
                rep(i,w-1)for (int j=i+1; j<w; ++j) {
                    if (jdx[i]>jdx[j]) ++sm;
                }
                chmin(ans,sm);
            }
        } while (next_permutation(all(jdx)));
    } while (next_permutation(all(idx)));
    print(ans==inf?-1:ans);

    return 0;
}
