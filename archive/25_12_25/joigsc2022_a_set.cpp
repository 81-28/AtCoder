// https://atcoder.jp/contests/joigsc2022/tasks/joigsc2022_a

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    for(auto&[b,a]:p) cin >> a >> b;
    // b[i]<=b[j]<=b[k]と固定して良い
    sort(all(p));
    // mi[j]:jを選ぶ場合の、(a[j]+b[j])+(a[k]+b[k])の最小値
    vi mi(n,INF);
    set<int> st;
    st.insert(p[n-1].f+p[n-1].s);
    for (int i=n-2; i>0; --i) {
        int sm=p[i].f+p[i].s;
        mi[i]=sm+*st.begin();
        st.insert(sm);
    }
    st.clear();
    st.insert(mi[n-2]);
    // 位置iと、それより上のmiの最小値の合計を最小化
    int ans=INF;
    for (int i=n-3; i>=0; --i) {
        chmin(ans,p[i].s+*st.begin());
        st.insert(mi[i]);
    }
    print(ans);

    return 0;
}
