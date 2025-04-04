// https://atcoder.jp/contests/abc309/tasks/abc309_a

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    a--,b--;
    puts(b-a==1&&a/3==b/3?"Yes":"No");
}
