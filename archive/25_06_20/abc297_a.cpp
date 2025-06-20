// https://atcoder.jp/contests/abc297/tasks/abc297_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    vi t(n);
    cin >> t;
    rep1(i,n-1) {
        if (t[i]-t[i-1]<=d) {
            print(t[i]);
            return 0;
        }
    }
    print(-1);

    return 0;
}