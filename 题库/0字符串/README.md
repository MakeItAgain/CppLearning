# 字符串习题汇总
本文档主要收录了与字符串相关的习题。关于字符串和字符数组而言，C语言中有字符串和字符数组之分，C++使用<string>类表示字符串。

## string常用函数
1. string和int的相互转化，我们知道，string和int是两种不同类型的数据，如何使用函数在这两种数据之间进行转换呢。  
string -> int，使用stoi函数`int x = stoi("1231");`  
int -> string，使用to_string函数`string str = to_string(1234);`   
