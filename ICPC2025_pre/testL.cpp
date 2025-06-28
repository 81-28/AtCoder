// https://2025domestic.jag-icpc.org/team/problems/5/text

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    while (1) {
        string s,t;
        cin >> s;
        if (s=="#") return 0;
        cin >> t;
        YesNo(s<t);
    }

    return 0;
}
