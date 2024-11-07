// https://atcoder.jp/contests/abc378/tasks/abc378_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi q(n),r(n);
    rep(i,n) cin >> q[i] >> r[i];

    int qn;
    cin >> qn;
    int t,d;
    rep(i,qn) {
        cin >> t >> d;
        int re = d % q[t-1];
        if (re <= r[t-1]) print(d+(r[t-1]-re));
        else print(d+(r[t-1]-re+q[t-1]));
    }

    return 0;
}
