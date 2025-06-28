// https://2025domestic.jag-icpc.org/team/problems/6/text

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l=0,r=1e9;
    while (1) {
        int m=(l+r)/2;
        print(m);
        char c;
        cin >> c;
        if (c=='=') return 0;
        else if (c=='<') r=m;
        else l=m+1;
    }

    return 0;
}
