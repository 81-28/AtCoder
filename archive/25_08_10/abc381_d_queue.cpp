// https://atcoder.jp/contests/abc381/tasks/abc381_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // x[i]:奇偶iに対して、{a[j]==a[j+1]となるj,その値a[j]}
    v<v<pii>> x(2);
    rep(i,n-1) {
        if (a[i]==a[i+1]) x[i%2].pb({i,a[i]});
    }
    // m[i]:現在使われている数の個数
    map<int,int> m;
    // q:現在使われている数
    queue<int> q;
    int ans=0;
    rep(i,2) {
        int last=-4;
        for (pii p:x[i]) {
            if (p.f-last!=2) {
                q=queue<int>();
                m=map<int,int>();
            }
            ++m[p.s];
            q.push(p.s);
            while (m[p.s]>1) {
                --m[q.front()];
                q.pop();
            }
            chmax(ans,(int)q.size());
            last=p.f;
        }
    }
    print(ans*2);

    return 0;
}
