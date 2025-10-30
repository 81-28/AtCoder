// https://atcoder.jp/contests/abc320/tasks/abc320_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi ans(n,0);
    set<int> st;
    rep(i,n) st.insert(i);
    // {時間,人}
    priority_queue<pii,v<pii>,greater<>> q;
    rep(i,m) {
        int t,w,s;
        cin >> t >> w >> s;
        while (!q.empty()) {
            auto[tt,j]=q.top();
            if (tt>t) break;
            q.pop();
            st.insert(j);
        }
        auto it=st.begin();
        if (it!=st.end()) {
            int idx=*it;
            st.erase(idx);
            ans[idx]+=w;
            q.push({t+s,idx});
        }
    }
    rep(i,n) print(ans[i]);

    return 0;
}
