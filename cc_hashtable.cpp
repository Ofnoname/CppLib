class cc_hashtable
{
    private:
        int hash(int pos) {
            return pos % 1234567;
        }

		struct node{
			node *nxt;
			int pos, val;
		}*a[1234567];
    public:
        int& operator[](int pos) {
			auto &hp = a[hash(pos)], p = hp;
			for (; p; p = p->nxt)
				if (p->pos == pos) return p->val;
			if (!p) {
				auto t(hp); 
				hp = new node{t, pos, 0}; return hp->val;
			}
		}
};