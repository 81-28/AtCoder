// https://atcoder.jp/contests/abc302/tasks/abc302_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

constexpr int inf=INT_MAX;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    map<int,vi> mp;
    rep1(i,n) {
        int a;
        cin >> a;
        rep1(j,a) {
            int s;
            cin >> s;
            mp[s].pb(m+i);
            mp[m+i].pb(s);
        }
    }
    queue<int> q;
    vi d(m+n+1,inf);
    q.push(1);
    d[1]=0;
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:mp[pos]) {
            if (chmin(d[nxt],d[pos]+1)) q.push(nxt);
        }
        if (d[m]!=inf) {
            print(d[m]/2-1);
            return 0;
        }
    }
    print(-1);

    return 0;
}
