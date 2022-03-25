class pairheap
{
	struct node { //! 左儿子右兄弟表示法
		int val; //* 类型
		node *l, *r, *lson;
	};
	private:
		node *root;
		auto merge(node *p, node *q) { //! 大的合并给小的， 另外一个将不再可用
			if (p->val > q->val) swap(p, q); //* 控制大小根
			q->l = p, q->r = p->lson; 
			if (p->lson) p->lson->l = q;
			p->lson = q; return p;
		}
		auto placemerge(auto l, auto r) {
			if (r - l == 1) return *l;
			if (r - l == 2) return merge(*l, *(l+1));
			else {
				auto mid = l + (r- l)/2;
				return merge(placemerge(l, mid), placemerge(mid, r));
			}
		}
	public:
		pairheap(): root(0) {}
		
		void push(auto val) {
			auto p = new node{val};
			root = root ? merge(p, root) : p;
		}
		auto pop() {
			auto val = root->val;

			vector<node*> t;
			for (auto p = root->lson; p; p = p->r) t.push_back(p);
			
			delete root;
			root = t.empty() ? 0 : placemerge(t.begin(), t.end());

			return val;
		}
		~pairheap() {
			//! 知道要写，但是没有写
		}
};