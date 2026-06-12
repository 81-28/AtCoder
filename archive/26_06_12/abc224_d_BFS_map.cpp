// https://atcoder.jp/contests/abc224/tasks/abc224_d

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using vvb=v<vb>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
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

    int n=9,m;
    cin >> m;
    vvb g(n,vb(n,0));
    while (m--) {
        int a,b;
        cin >> a >> b;
        g[a][b]=g[--b][--a]=1;
    }
    vi p(n-1);
    cin >> p;
    for (int& val:p) --val;
    // d[vec]:コマの位置vecにするために必要な最小回数
    d_map<vi,int> d(INF);
    queue<vi> q;
    d[p]=0;
    q.push(p);
    while (!q.empty()) {
        vi now=q.front();
        q.pop();
        int dist=d[now];
        vb b(n,0);
        for (int val:now) b[val]=1;
        int num=0;
        rep(i,n) {
            if (!b[i]) {
                num=i;
                break;
            }
        }
        rep(i,n-1) {
            if (!g[now[i]][num]) continue;
            vi nxt=now;
            nxt[i]=num;
            if (chmin(d[nxt],dist+1)) q.push(nxt);
        }
    }
    vi vec(n-1);
    rep(i,n-1) vec[i]=i;
    int ans=d[vec];
    print(ans==INF?-1:ans);

    return 0;
}
