class graph {

protected:
	using ver = unsigned;

    struct edg {
        int w, nxt;
        ver v;
    } e[MAXM * 2];

	int n, m, head[MAXN];
public:
	void add_edge(int u, int v, int w) {
        static auto cnt = 2;
        e[cnt] = {w, head[u], v};
        head[u] = cnt++;
    }
};