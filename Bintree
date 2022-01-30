#ifndef BINTREE_H
#define BINTREE_H

//! 仅算术类型
template <typename Type, unsigned N>
class Bintree;

template <typename Type, unsigned N>
class Bintree
{
	using index = unsigned;
	private:
		Type a[N + 1];
		inline index lowbit(index x) {
			return x & -x;
		}

	public:
		void add(index i, Type v) {
			for (; i <= N; i += lowbit(i)) a[i] += v;
		}
		Type sum(index i) {
			Type ans = 0;
			for (; i; i -= lowbit(i)) ans += a[i];
			return ans;
		}
};
#endif