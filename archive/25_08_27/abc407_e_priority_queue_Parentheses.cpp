// https://atcoder.jp/contests/abc407/tasks/abc407_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n*2);
        cin >> a;
        priority_queue<int> q;
        // i=0は採用,残りは2つごとに見て、現在の最大を1つ採用
        int ans=a[0];
        rep1(i,n-1) {
            q.push(a[i*2-1]);
            q.push(a[i*2]);
            ans+=q.top();
            q.pop();
        }
        print(ans);
    }

    return 0;
}
