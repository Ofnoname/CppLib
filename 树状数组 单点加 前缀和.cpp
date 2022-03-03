//* 树状数组
template <typename Type, unsigned N>
class Bintree
{
	using index = unsigned;
	private:
		Type a[N + 1];
		index lowbit(index x) {
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
//* 树状数组