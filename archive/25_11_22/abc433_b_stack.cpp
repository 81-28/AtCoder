// https://atcoder.jp/contests/abc433/tasks/abc433_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

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
    // {高さ,idx}
    stack<pii> st;
    rep(i,n) {
        bool ok=0;
        while (!st.empty()) {
            auto[h,j]=st.top();
            if (h>a[i]) {
                print(j+1);
                ok=1;
                break;
            }
            st.pop();
        }
        if (!ok) print(-1);
        st.push({a[i],i});
    }

    return 0;
}
