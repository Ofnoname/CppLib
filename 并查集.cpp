class UFS
{
	using ver = int;

	ver in[MAX], size[MAX];
	ver find(ver u) {
		return in[u]==u ? u : (in[u] = find(in[u]));
	}

	size_t N;

	public:
		UFS(size_t N) {
			std::iota(in, in + N, 0);
			std::fill(size, size + N, 1);
		}
		void set(ver u, ver v) {
			u = find(u), v = find(v);
			size[u]<size[v] ? in[u] = v : in[v] = u;
		}
		bool get(ver u, ver v) {
			return find(u) == find(v);
		}
};