clang -cc1 -fdump-record-layouts -emit-llvm  $1 > clang-vtable-layout-$1.txt
clang -cc1 -fdump-vtable-layouts -emit-llvm  $1 > clang-record-layout-$1.txt
g++ -fdump-lang-class=$1_gcc.txt $1
# g++ -fdump-lang-all=$1_gcc_all.txt $1