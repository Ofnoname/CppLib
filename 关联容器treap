struct node {
	i64 pos, val, seed;
	node *ls, *rs;
} pool[MAX];
node * const null = pool;
node* newnode(i64 pos, i64 val) {
	static node* p = pool;
	return new(++p) node{pos, val, rand(), null, null};
}

class Treap
{
	void zag(node* &p) {
		node* q = p->rs;
		p->rs = q->ls, q->ls = p, p = q;
	}
	void zig(node* &p) {
		node* q = p->ls;
		p->ls = q->rs, q->rs = p, p = q;
	}

	public:		
		node* root = null;

		void set(node* &p, i64 pos, i64 val) {
			if (p != null) {
				if (p->pos == pos) {
					p->val = val; return;
				}
				else if (p->pos<pos) {
					set(p->rs, pos, val);
					if (p->rs->seed < p->seed) zag(p);
				}
				else {
					set(p->ls, pos, val);
					if (p->ls->seed < p->seed) zig(p);
				}
			}
			else {
				p = newnode(pos, val); return;
			}
		}
		i64 get(node* p, i64 pos) const {
			while(p != null) {
				if (p->pos == pos) return p->val;
				else p = p->pos<pos ? p->rs : p->ls;
			} return 0;
		}
};