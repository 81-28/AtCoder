// https://atcoder.jp/contests/abc463/tasks/abc463_e

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
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


template<typename K,typename V>
class d_map:public map<K,V>{
public:
    V d_val;
    d_map(const V& default_value):d_val(default_value){}
    V& operator[](const K& key) {
        auto it=this->find(key);
        if (it==this->end()) {
            it=this->emplace(key,d_val).first;
        }
        return it->second;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,y;
    cin >> n >> m >> y;
    vector mp(n+1,d_map<int,int>(INF));
    rep(i,m) {
        int u,v,t;
        cin >> u >> v >> t;
        --u,--v;
        chmin(mp[u][v],t);
        chmin(mp[v][u],t);
    }
    vi x(n);
    rep(i,n) {
        cin >> x[i];
        chmin(mp[i][n],x[i]);
        chmin(mp[n][i],x[i]+y);
    }
    vi d(n+1,INF);
    // {距離,位置}
    priority_queue<pii,v<pii>,greater<>> q;
    d[0]=0;
    q.push({0,0});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (d[pos]<dist) continue;
        for (auto[nxt,t]:mp[pos]) {
            if (chmin(d[nxt],dist+t)) q.push({d[nxt],nxt});
        }
    }
    rep(i,n-1) cout<<d[i+1]<<' ';
    cout<<endl;

    return 0;
}
