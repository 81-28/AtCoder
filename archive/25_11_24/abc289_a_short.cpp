// https://atcoder.jp/contests/abc289/tasks/abc289_a

#include<iostream>
main(){for(char c;std::cin>>c;)std::cout<<49-c;}

// 最後がEOF(-1)ではなく'\n'(10)で判定すると、AC
#include<cstdio>
main(){for(int c;(c=getchar())-10;)putchar(97-c);}
