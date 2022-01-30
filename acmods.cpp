//* 2022-01-11
#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using d64 = double;


// fread读入整数，单字符
//todo 输出 多参数
class Istream
{
	#define BUF_SIZE  unsigned(1 << 21)
	char buf[BUF_SIZE], *p1 = buf, *p2 = buf;

	public:
	char getchar() {
		return (p1==p2 && (p2=(p1=buf) + fread(buf,1,BUF_SIZE,stdin), p1==p2)?EOF : *p1++);
	}

	template <class T>
	void read(T &a) {
		char c = 0;
		bool f = 0;
		for (a=0; !isdigit(c); c = getchar())
			if (c == '-') f = 1;
		for (; isdigit(c); c = getchar())
			a = a * 10 + f ? ('0'-c):(c-'0');
	}
	template <class T, class... Args>
	void read(T &a, Args& ...rest) {
		read(a);
		read(rest...);
	}
	#undef BUF_SIZE
}Cin;




// 基础树状数组, 序列单点加，前缀和
class Bintree{
	i64 a[/**/];
	inline u32 lowbit(u32 x) {
		return x & -x;
	}

	public:
	void add(u32 i, i64 v) {
		for (; i <= N; i += lowbit(i)) a[i] += v;
	}
	i64 sum(u32 i) {
		i64 ans = 0;
		for (; i; i -= lowbit(i)) ans += a[i];
		return ans;
	}
};

// 1-based KMP
void KMP(char *s1, char *s2, int len1, int len2) { //! s1是长串，s2是短串，1based
	int nxt[len2 + 1] = {};
	for (int i = 2, j = 0; i <= len2; i++) {
		while (j && s2[i] != s2[j+1]) j = nxt[j];
		nxt[i] = (s2[i] == s2[j+1]) ? ++j : 0;
	}
	for (int i = 1, j = 0; i <= len1; i++) {
		while ((j && s1[i] != s2[j+1]) || j==len2) j = nxt[j];
		if (s1[i] == s2[j+1] && ++j==len2) {
			//! 匹配成功
		}
	}
}
void Manacher(char *s, int len, int *f) {//! 1based
	int maxR = 0, mid = 0;
	for (int i = 1; i <= len; i++) {
		f[i] = (i < maxR) ? std::min(f[mid * 2 - i], f[mid] + mid - i) : 1;
		while (s[i + f[i]] == s[i - f[i]])//! 未判断下标越界
			++f[i];
		if (i + f[i] > maxR)
			maxR = (mid = i) + f[i];
	}
}