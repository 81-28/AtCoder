// https://atcoder.jp/contests/arc214/tasks/arc214_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    cin >> s;
    rep(i,n) {
        set<int> st;
        for (int x=i,y=0; x>=0; --x,++y) {
            if (s[x][y]=='?') continue;
            st.insert(s[x][y]-'0');
        }
        if (st.size()>1) {
            print(-1);
            return 0;
        }
        if (st.size()==0) st.insert(0);
        for (int x=i,y=0; x>=0; --x,++y) s[x][y]=('0'+*st.begin());
    }
    rep1(i,n-1) {
        set<int> st;
        for (int x=i,y=n-1; x<n; ++x,--y) {
            if (s[x][y]=='?') continue;
            st.insert(s[x][y]-'0');
        }
        if (st.size()>1) {
            print(-1);
            return 0;
        }
        if (st.size()==0) st.insert(0);
        for (int x=i,y=n-1; x<n; ++x,--y) s[x][y]=('0'+*st.begin());
    }
    rep(i,n) print(s[i]);

    return 0;
}
