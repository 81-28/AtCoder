// https://atcoder.jp/contests/abc287/tasks/abc287_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    unordered_set<string> st;
    while (m--) {
        string t;
        cin >> t;
        st.insert(t);
    }
    int ans=0;
    for (string str:s) {
        ans+=(st.find(str.substr(3,3))!=st.end());
    }
    print(ans);

    return 0;
}
