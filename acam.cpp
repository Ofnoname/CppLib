/* 
 *	AC自动机
 *	2022-04-18
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

class acam {
	struct node 
	{
		vector<int> end; //! 以我结尾
		int deg;
		
		node *fail, *to[26]; //! 26字母	
	};

private:
	node pool[MAX], *cpool = pool; //! 字符总数
	node *root = pool; //! 

	vector<string> s; //! 保存原串
public:
	acam() {
		//? 1. 构造trie
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string t; cin >> t;

			auto p(root);
			for (auto c: t) {
				auto& np(p->son[c - 'a']); //! 小写
				if (!np) np = ++cpool; p = np;
			}

			s.push_back(move(t));
			p->end.push_back(i);
		}

		//? 2. 构造AC自动机
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

	void match() {
		
	}
};