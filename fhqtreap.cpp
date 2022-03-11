class fhqtreap{
	struct node
	{
		node *ls, *rs;
		int seed, val, size, tag;
	}*const null, *root;

	void pushdown(node *p) {
		
	}
	void pushup(node *p) {
		
	}
	
	void split(node *p, node *&x, node *&y, int k) {
		if (p == null) {
			x = y = null;
			return;
		}
		pushdown(p);
		if (p->ls->size < k) {
			x = p;
			split(p->rs, p->rs, y, k - (p->ls->size) - 1);
		}
		else {
			y = p;
			split(p->ls, x, p->ls, k);
		}
		pushup(p);
	}

	node* merge(node *x, node *y) {
		if (x == null || y == null)
			return std::max(x, y);
		if (x->seed < y->seed) {
			pushdown(x);
			x->rs = merge(x->rs, y);
			pushup(x);
			return x;
		}
		else {
			pushdown(y);
			y->ls = merge(x, y->ls);
			pushup(y);
			return y;
		}
	}
	
	public:
		fhqtreap():null(new node), root(null) {

		}
};
