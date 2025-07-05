// https://atcoder.jp/contests/abc413/tasks/abc413_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

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
    set<string> st;
    rep(i,n-1)for(int j=i+1; j<n; ++j) {
        st.insert(s[i]+s[j]);
        st.insert(s[j]+s[i]);
    }
    print(st.size());

    return 0;
}
