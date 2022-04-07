class gp_hashtable
{
private:
	auto hash(auto pos) {
		return pos % 3456789;
	}
	auto offset(bool reset = 0) {
		static auto seed(0ull);
		return reset ? (seed = 0) : (seed += seed + 1);
	}

	struct node{
		u64 pos, val;
	}*a[3456789];
public:
	auto& operator[](auto pos) { //!不存在的key会新建并返回0
		auto hp(hash(pos));

		while (a[hp] && a[hp]->pos != pos) {
			hp += offset();
			if (hp >= 3456789) hp %= 3456789;
		}
		if (!a[hp]) a[hp] = new node{pos, 0};
		offset(1);
		return a[hp]->val;
	}
};