//* 并查集
//* 2021-03-29
class ufs
{
	using ver = int;

	ver in[MAX], size[MAX];
	ver find(ver u) {
		return in[u]==u ? u : (in[u] = find(in[u])); //! 路径压缩
        // return in[u]==u ? u : find(in[u]); //! 不压缩
	}

	public:
		ufs() {
			std::iota(in, in + N, 0);
			std::fill(size, size + N, 1);
		}
		void set(ver u, ver v) {
			u = find(u), v = find(v);
			if (size[u] < size[v]) swap(u, v); //! 让u > v
            in[v] = u, size[u] += size[v]; //! 按大小合并
		}
		bool get(ver u, ver v) {
			return find(u) == find(v);
		}
};