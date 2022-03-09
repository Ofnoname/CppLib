class segtree
{
	struct node {
		int mat[4];
		node *ls, *rs;
		void pushup() {
			int tmp[] = {(1ll*ls->mat[0]*rs->mat[0] + ls->mat[1]*rs->mat[2]) % mod,
						 (1ll*ls->mat[0]*rs->mat[1] + ls->mat[1]*rs->mat[3]) % mod,
						 (1ll*ls->mat[2]*rs->mat[0] + ls->mat[3]*rs->mat[2]) % mod,
						 (1ll*ls->mat[2]*rs->mat[1] + ls->mat[3]*rs->mat[3]) % mod};
			move(tmp, tmp+4, mat);
		}
	}*const null, *root;

	node* build(int l, int r, const auto &rec) {
		if (r - l == 1) return new node{rec[l].first, 0, rec[l].second, 1, null, null};
		if (r - l > 1) {
			int mid = (l + r) / 2;
			auto p = new node{0, 0, 0, 0, build(l, mid, rec), build(mid, r, rec)};
			p->pushup(); return p;
		}
	}
	void set(int pos, int nk, int nb, node* &p, int l = 0, int r = N) {
		if (r - l == 1) {
			int tmp[4] = {nk, 0, nb, 1};
			move(tmp, tmp+4, p->mat);
		}
		else {
			int mid = (l + r) / 2;
			pos<mid ? set(pos, nk, nb, p->ls, l, mid):
					  set(pos, nk, nb, p->rs, mid, r);
			p->pushup();
		}
	}
	void get(int lpos, int rpos, node * &p, int &x, int &y, int l = 0, int r = N) const {
		if (lpos >= r || rpos <= l) return;
		if (lpos <= l && r <= rpos) {
			int nx = (1ll*x*p->mat[0] + y*p->mat[2]) % mod,
				ny = (1ll*x*p->mat[1] + y*p->mat[3]) % mod;
			x = nx, y = ny; return;
		}
		int mid = (l + r ) / 2;
		get(lpos, rpos, p->ls, x, y, l, mid);
		get(lpos, rpos, p->rs, x, y, mid, r);
	}
	void destroy(int l, int r, node* &p) {
		if (r - l > 1) {
			int mid = (l + r ) /2;
			destroy(l, mid, p->ls), destroy(mid, r, p->rs);
		}delete p;
	}

	public:
		segtree(): null{} {
			vector<pair<int,int>> rec(N);
			it(i, 0, N) cin >> rec[i].first >> rec[i].second;
			root = build(0, N, rec);
			if (N > 1) root->pushup();
		}
		void set(int pos, int nk, int nb) {
			set(pos, nk, nb, root);
		}
		int get(int lpos, int rpos, int x) {
			int y = 1;
			get(lpos, rpos, root, x, y); return x;
		}
		~segtree() {
			destroy(0, N, root);
		}
};