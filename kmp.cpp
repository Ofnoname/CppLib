class kmp
{
private:
	const string &s;
	vector<int> nxt;
public:
	kmp(const string &_s): s(_s) {
		auto lst(0);

		nxt.push_back(0); //! nxt_0赋值为0
		for (int i = 1; i < s.size(); ++i) {
			while (lst && s[lst] != s[i])
				lst = nxt[lst-1];
			nxt.push_back((s[lst] == s[i]) ? ++lst : 0);
		}
	}
	void print() {
		for (auto i : nxt) cout << i << ' ';
	}
};