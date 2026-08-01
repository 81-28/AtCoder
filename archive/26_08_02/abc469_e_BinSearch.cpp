// https://atcoder.jp/contests/abc469/tasks/abc469_e

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n,k;
vi sm;
// 勝率が d 以上の区間が存在するかを判定する。
// 区間 [l, r] について
//   (sm[r] - sm[l-1]) / (r - (l-1)) >= d
// を変形すると
//   sm[r] - d*r >= sm[l-1] - d*(l-1)
// となる。
// さらに勝ち数が K 以上必要なので、
//   sm[l-1] <= sm[r] - K
// を満たす left だけを候補にする。
// 右端 r を走査しながら、使える left の中で最小の
//   sm[left] - d*left
// を best に保てば、各 r を O(1) で判定できる。
// ptr は左から右へしか進まないので、全体でも高々 N 回しか進まず、
// ok(d) 全体の計算量は O(N) になる。
bool ok(ld d) {
    ld best = 1e100;
    int ptr = -1;
    rep1(r, n) {
        while (ptr + 1 < r && sm[ptr + 1] <= sm[r] - k) {
            ++ptr;
            best = min(best, (ld)sm[ptr] - d * ptr);
        }
        if ((ld)sm[r] - d * r - best >= -1e-18) return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    string s;
    cin >> n >> k >> s;
    sm=vi(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+(s[i-1]=='o');

    ld lo=0,hi=1;
    rep1(i,20) {
        ld m=(lo+hi)/2;
        if (ok(m)) lo=m;
        else hi=m;
    }
    print(lo);

    return 0;
}
