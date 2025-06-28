// https://2025domestic.jag-icpc.org/team/problems/4/text

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    while (1) {
        int a,b;
        cin >> a >> b;
        int m=a*b;
        if (m) print(m);
        else return 0;
    }

    return 0;
}
