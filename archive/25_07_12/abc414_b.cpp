// https://atcoder.jp/contests/abc414/tasks/abc414_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0;
    string str="";
    rep(i,n) {
        string t;
        int m;
        cin >> t >> m;
        sm+=m;
        if (sm>100) {
            print("Too Long");
            return 0;
        }
        rep(j,m) str+=t;
    }
    print(str);

    return 0;
}
