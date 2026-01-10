// https://atcoder.jp/contests/abc440/tasks/abc440_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,w;
        cin >> n >> w;
        vi c(n);
        cin >> c;
        // ans[i]:xがiの時のコスト
        vi ans(2*w,0);
        int sm=0;
        rep(i,n+w) {
            if (i<n) sm+=c[i];
            if (i-w>=0) sm-=c[i-w];
            ans[i%(2*w)]+=sm;
        }
        print(min(ans));
    }

    return 0;
}
