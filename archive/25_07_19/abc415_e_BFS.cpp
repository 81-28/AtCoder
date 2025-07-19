// https://atcoder.jp/contests/abc415/tasks/abc415_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    vvi a(h,vi(w));
    vi p(h+w-1);
    cin >> a >> p;
    // ans[i][j]:マスijで、最初に必要なコイン枚数の最小値
    vvi ans(h,vi(w,1e16));
    ans[h-1][w-1]=max(*p.rbegin()-a[h-1][w-1],0LL);
    queue<tuple<int,int,int>> q;
    q.push({h-1,w-1,h+w-3});
    while (!q.empty()) {
        auto[x,y,i]=q.front();
        q.pop();
        if (x>0) {
            if (chmin(ans[x-1][y],max(ans[x][y]+p[i]-a[x-1][y],0LL))) q.push({x-1,y,i-1});
        }
        if (y>0) {
            if (chmin(ans[x][y-1],max(ans[x][y]+p[i]-a[x][y-1],0LL))) q.push({x,y-1,i-1});
        }
    }
    print(ans[0][0]);

    return 0;
}
