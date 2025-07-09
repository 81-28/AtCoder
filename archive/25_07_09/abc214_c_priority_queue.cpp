// https://atcoder.jp/contests/abc214/tasks/abc214_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T>constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi s(n),t(n);
    cin >> s >> t;
    // {時間,idx}
    priority_queue<pii> q;
    rep(i,n) q.push({t[i],i});
    while (!q.empty()) {
        auto [time,idx]=q.top();
        q.pop();
        if (time>t[idx]) continue;
        int nxt=(idx+1)%n;
        if (chmin(t[nxt],time+s[idx])) q.push({t[nxt],nxt});
    }
    rep(i,n) print(t[i]);

    return 0;
}
