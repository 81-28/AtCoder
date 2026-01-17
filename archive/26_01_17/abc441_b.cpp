// https://atcoder.jp/contests/abc441/tasks/abc441_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
using vvb=v<vb>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,q;
    string s,t;
    cin >> n >> m >> s >> t >> q;
    vvb a(2,vb(26,0));
    for (char c:s) a[0][c-'a']=1;
    for (char c:t) a[1][c-'a']=1;
    while (q--) {
        string w;
        cin >> w;
        bool ok0=1,ok1=1;
        for (char c:w) {
            if (!a[0][c-'a']) ok0=0;
            if (!a[1][c-'a']) ok1=0;
        }
        if (ok0==ok1) print("Unknown");
        else {
            if (ok0) print("Takahashi");
            else print("Aoki");
        }
    }

    return 0;
}
