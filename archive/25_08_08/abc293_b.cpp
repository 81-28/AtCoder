// https://atcoder.jp/contests/abc293/tasks/abc293_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
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
    vi a(n);
    cin >> a;
    set<int> s;
    rep1(i,n) s.insert(i);
    rep(i,n) {
        if (s.find(i+1)!=s.end()) {
            auto it=s.find(a[i]);
            if (it!=s.end()) s.erase(it);
        }
    }
    print(s.size());
    for (int val:s) cout<<val<<' ';
    cout<<endl;

    return 0;
}
