// 右邊第一個 1 的位置
int __builtin_ffs(unsigned int);
int __builtin_ffsl(unsigned long);
int __builtin_ffsll(unsigned long long);
// 左邊第一個 1 之前 0 的數量
int __builtin_clz(unsigned int);
int __builtin_clzl(unsigned long);
int __builtin_clzll(unsigned long long);
// 右邊第一個 1 之後 0 的數量
int __builtin_ctz(unsigned int);
int __builtin_ctzl(unsigned long);
int __builtin_ctzll(unsigned long long);
// 1 的數量
int __builtin_popcount(unsigned int);
int __builtin_popcountl(unsigned long);
int __builtin_popcountll(unsigned long long);
// 1 的數量 mod 2
int __builtin_parity(unsigned int);
int __builtin_parityl(unsigned long);
int __builtin_parityll(unsigned long long);
// 二進制表示數字
int a = 0b101101;