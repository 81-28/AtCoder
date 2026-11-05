// https://atcoder.jp/contests/abc255/tasks/abc255_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,k;
    cin >> n >> k;
    vi a(k);
    for (int&b:a) {
        cin >> b;
        --b;
    }
    v<pii> p(n);
    for (auto&[x,y]:p) cin >> x >> y;
    int ans=0;
    for (auto[x,y]:p) {
        int res=INF;
        for (int i:a) {
            auto[xx,yy]=p[i];
            chmin(res,(xx-x)*(xx-x)+(yy-y)*(yy-y));
        }
        chmax(ans,res);
    }
    print(sqrt(ans));

    return 0;
}
