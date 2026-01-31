// https://atcoder.jp/contests/abc443/tasks/abc443_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi r(n);
        cin >> r;
        vi rr=r;
        // {行番号,idx}
        priority_queue<pii,v<pii>,greater<>> q;
        vi ans(n,INF);
        rep(i,n) {
            if (i) {
                if (i+1<n) {
                    if (r[i-1]>=r[i] && r[i]<=r[i+1]) {
                        q.push({r[i],i});
                        ans[i]=r[i];
                    }
                } else {
                    if (r[i-1]>=r[i]) {
                        q.push({r[i],i});
                        ans[i]=r[i];
                    }
                }
            } else {
                if (r[i]<=r[i+1]) {
                    q.push({r[i],i});
                    ans[i]=r[i];
                }
            }
        }
        while (!q.empty()) {
            auto[h,i]=q.top();
            q.pop();
            if (h>ans[i]) continue;
            if (i) {
                if (chmin(ans[i-1],h+1)) q.push({ans[i-1],i-1});
            }
            if (i+1<n) {
                if (chmin(ans[i+1],h+1)) q.push({ans[i+1],i+1});
            }
        }
        int sm=0;
        rep(i,n) sm+=rr[i]-ans[i];
        print(sm);
    }

    return 0;
}
