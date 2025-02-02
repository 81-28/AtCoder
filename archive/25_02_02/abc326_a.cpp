// https://atcoder.jp/contests/abc326/tasks/abc326_a
#include<iostream>
int main(){
    int x,y;
    std::cin>>x>>y;
    std::cout<<(x-4<y&&y<x+3?"Yes\n":"No\n");
}