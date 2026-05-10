// https://atcoder.jp/contests/abc244/tasks/abc244_d

#include<bits/stdc++.h>
using namespace std;

using tc=tuple<char,char,char>;

template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    set<tc> st={
        {'R','G','B'},{'G','B','R'},{'B','R','G'}
    };
    tc s,t;
    cin >> s >> t;
    YesNo((st.find(s)!=st.end()) == (st.find(t)!=st.end()));

    return 0;
}
