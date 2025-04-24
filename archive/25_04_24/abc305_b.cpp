// https://atcoder.jp/contests/abc305/tasks/abc305_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi s={0,3,4,8,9,14,23};
    char p,q;
    cin >> p >> q;
    int a=p-'A',b=q-'A';
    print(s[max(a,b)]-s[min(a,b)]);

    return 0;
}
