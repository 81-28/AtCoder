// https://atcoder.jp/contests/abc468/tasks/abc468_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi p(n),q(n);
    cin >> p >> q;
    int ans=-1;
    bool ok=0;
    do {
        if (p==q) {
            ok=1;
            break;
        }
        ++ans;
    } while (next_permutation(all(p)));
    print(max(0,ok?ans:0));

    return 0;
}
