ファイルのあるディレクトリに cd : Alt + c


Build : Ctrl + Shift + B


Run   : `./a.out < ./1.in`
Out   : `./a.out < ./1.in > 1.out`
Check : `diff 1.ans 1.out`


ACL展開 : `./expand.sh`
(`python3 ../../../ac-library/expander.py --lib ../../../ac-library/ a.cpp`)
