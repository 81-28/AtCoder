// https://atcoder.jp/contests/abc478/tasks/abc478_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi q(n);
    cin >> q;
    stack<int> s;
    mint ans=1;
    rep(i,n) {
        // q[i]より大きい要素があったら、その内一番最近のものにつけるしかない
        while (!s.empty() && q[s.top()]<q[i]) s.pop();
        if (i) {
            int l=0;
            if (!s.empty()) l=s.top();
            ans*=i-l;
        }
        s.push(i);
    }
    print(ans.val());

    return 0;
}
