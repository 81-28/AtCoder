// https://atcoder.jp/contests/abc300/tasks/abc300_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    cin >> n >> a >> b;
    vi c(n);
    cin >> c;
    rep(i,n) {
        if (a+b==c[i]) {
            print(i+1);
            return 0;
        }
    }

    return 0;
}
