//* 01trie
//* 2022-03-29
class _01trie
{
	struct node{
		node *s[2]; //! 无重复数标记
	}*root;

	public:
		_01trie(): root(new node) {}

		void insert(int val) { 
			auto p(root);
			for (int b = 30; ~b; --b) { //! 31位整数
				auto &t = p->s[val >> b & 1];
				if (!t) t = new node; p = t;
			}
		}
		int find_maxxor(int val) const { //! 寻找和val异或最大的值
			auto p(root); int ans = 0;
			//! 未处理树为空的情况，会炸
			for (int b = 30; ~b; --b) {
				if (p->s[!(val >> b & 1)]) {
					p = p->s[!(val >> b & 1)];
					ans |= 1 << b;
				}
				else p = p->s[val >> b & 1];
			} return ans;
		}

		~_01trie() {
			//todo 知道要写 但没写
		}
};