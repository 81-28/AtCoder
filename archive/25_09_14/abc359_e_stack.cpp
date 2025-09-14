// https://atcoder.jp/contests/abc359/tasks/abc359_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi h(n);
    cin >> h;
    // {高さ,幅}
    stack<pii> st;
    st.push({h[0],1});
    vi ans(n);
    ans[0]=h[0]+1;
    for (int i=1; i<n; ++i) {
        ans[i]=ans[i-1];
        int nl=h[i],nw=1;
        while (!st.empty()) {
            auto[l,w]=st.top();
            if (l<=nl) {
                st.pop();
                nw+=w;
                ans[i]-=l*w;
            } else break;
        }
        st.push({nl,nw});
        ans[i]+=nl*nw;
    }
    print(ans);

    return 0;
}
