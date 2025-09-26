// https://atcoder.jp/contests/abc329/tasks/abc329_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi c(n);
    cin >> c;
    v<set<int>> s(n);
    rep(i,n) s[i].insert(c[i]);
    map<int,int> m;
    rep(i,n) m[i]=i;
    while (q--) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        if (s[m[a]].size()>s[m[b]].size()) {
            int temp=m[b];
            m[b]=m[a];
            m[a]=temp;
        }
        for (auto it=s[m[a]].begin(); it!=s[m[a]].end(); it=s[m[a]].erase(it)) s[m[b]].insert(*it);
        print(s[m[b]].size());
    }

    return 0;
}
