class Tree
{
	using ver = int;

	std::vector<ver> son[MAX];
	int dep[MAX], anc[MAX][21];

	void get_dep_fa(ver u) {
		for (auto v: son[u]) {
			dep[v] = dep[u] + 1, anc[v][0] = u;
			get_dep_fa(v);
		}
	}

	public:
		#define root 0
		Tree() {
			for (int i = 1; i < N; ++i) son[p[i]].push_back(i);
			get_dep_fa(root);

			for (int i = 1; i < 21; ++i) for (int u = 0; u < N; ++u)
				anc[u][i] = anc[anc[u][i-1]][i-1];
		}
		ver getLCA(ver u, ver v) {
			if (dep[u] < dep[v]) std::swap(u, v);
			for (int i = 20; ~i; --i) if ((dep[u]-dep[v]) & (1 << i)) u = anc[u][i];

			if (u == v) return u;
			for (int i = 20; ~i; --i) if (anc[u][i] != anc[v][i]) 
				u = anc[u][i], v = anc[v][i];
			return anc[u][0];
		}
		#undef root
};