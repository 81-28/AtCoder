// https://atcoder.jp/contests/abc264/tasks/abc264_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    map<char,int> idx={{'a',0},{'t',1},{'c',2},{'o',3},{'d',4},{'e',5},{'r',6}};
    string s;
    cin >> s;
    int n=s.size();
    segtree<S,op,e> t(n);
    int ans=0;
    for (char c:s) {
        ans+=t.prod(idx[c],n);
        t.set(idx[c],1);
    }
    print(ans);

    return 0;
}
