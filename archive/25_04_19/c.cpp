// https://atcoder.jp/contests/abc402/tasks/abc402_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
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
    int ans=0;
    v<unordered_set<int>> s(n+1);
    vi k(m);
    vi a;
    rep(i,m) {
        cin >> k[i];
        a=vi(k[i]);
        cin >> a;
        rep(j,k[i]) {
            s[a[j]].insert(i);
        }
    }
    int b;
    rep(i,n) {
        cin >> b;
        for (int val:s[b]) {
            k[val]--;
            if (k[val]==0) ans++;
        }
        print(ans);
    }

    return 0;
}
