// https://atcoder.jp/contests/abc393/tasks/abc393_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<set<int>> a(n);
    int ans=0;
    vi u(2);
    rep(i,m) {
        cin >> u;
        if (u[0]==u[1]) {
            ans++;
        } else {
            sort(all(u));
            if (a[u[0]].find(u[1]) == a[u[0]].end()) {
                a[u[0]].insert(u[1]);
            } else ans++;
        }
    }
    print(ans);

    return 0;
}
