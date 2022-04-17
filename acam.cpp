class acam {
	struct node {
		int cnt, deg, endcnt; //! deg记录入度
		node *fail, *son[26];
	} *root, a[MAX], *cnt = a;

private:
	void insert(const string &s) {
		auto p(root);

		for (auto c: s) {
			auto& np(p->son[c - 'a']);

			if (!np) np = cnt++;
			p = np;
		} ++p->endcnt;
	}

	void getfail()
	{
		queue<node*> q;

		root->fail = root; //! root下第一层节点的入队
		for (auto &np: root->son) {
			if (np) {
				q.push(np);
				np->fail = root;
			}
			else np = root;
		}

		while (!q.empty()) {
			auto p(q.front()); q.pop();

			for (int i = 0; i < 26; i++) {
				auto &np(p->son[i]);

				if (np) {
					(np->fail = p->fail->son[i])->deg++;
					q.push(np);
				}
				else np = p->fail->son[i];
			}
		}
	}

public:
	acam(): root(new node) 
	{
		int n; cin >> n;
		while (n--) {
			string s; cin >> s;
			insert(s);
		}
		getfail();
	}
	void match(const string &s) 
	{
		auto p (root);
		for (auto c: s) { //! 先过字符串
            p = p->son[c-'a'];
            ++p->cnt;
        }

		long long ans(0); queue<node*> q;
		for (auto i(a); i < cnt; ++i) 
            if (!i->deg) q.push(i);
		while (!q.empty()) { 
            auto p(q.front()); q.pop();
            auto np(p->fail); np->deg--;

            np->cnt += p->cnt;
            if (p->cnt) ans += p->endcnt;
            if (!np->deg) q.push(np);
        } cout << ans;
	}
};