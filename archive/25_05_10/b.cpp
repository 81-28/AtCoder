// https://atcoder.jp/contests/abc405/tasks/abc405_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
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
    vi a(n);
    cin >> a;
    int c=0;
    map<int,int> mp;
    rep(i,n) {
        ++mp[a[i]];
        if (mp[a[i]]==1) ++c;
        if (c==m) {
            print(n-i);
            return 0;
        }
    }
    print(0);


    return 0;
}
