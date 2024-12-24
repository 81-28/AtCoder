// https://codeforces.com/gym/105633/problem/B

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

ll f(const ll& a, const ll& b) {
    if (a==b) return a;
    int la = log2(a),lb = log2(b);
    ll pa = pow(2,la);
    if (la != lb) {
        return pa == a ? pa : pa*2;
    }
    return pa+f(a-pa,b-pa);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll a,b;
    cin >> a >> b;
    print(f(a,b));

    return 0;
}
