// https://atcoder.jp/contests/abc324/tasks/abc324_b

#include<bits/stdc++.h>
int main(){
    long long n;
    std::cin>>n;
    while(n%2==0)n/=2;
    while(n%3==0)n/=3;
    std::cout<<(n==1?"Yes\n":"No\n");
}