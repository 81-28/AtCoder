// https://atcoder.jp/contests/abc446/tasks/abc446_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        vi a(n),b(n);
        cin >> a >> b;
        // {日付,個数}
        deque<pii> q;
        rep(i,n) {
            q.pb({i,a[i]});
            int sm=0;
            while (sm<b[i]) {
                if (q.empty()) break;
                auto[num,cnt]=q.front();
                if (sm+cnt<=b[i]) {
                    sm+=cnt;
                    q.pop_front();
                } else {
                    q.front().s-=b[i]-sm;
                    sm=b[i];
                    break;
                }
            }
            while (!q.empty()) {
                auto[num,cnt]=q.front();
                if (i-num<d) break;
                q.pop_front();
            }
        }
        int ans=0;
        while (!q.empty()) {
            auto[num,cnt]=q.front();
            q.pop_front();
            ans+=cnt;
        }
        print(ans);
    }

    return 0;
}
