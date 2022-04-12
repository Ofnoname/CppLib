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

	void match(const string &S) { //! 匹配长串S
		auto lst(0), ans(0);
	
		for (int i = 0; i < S.size(); ++i) {
			while (lst && (lst==s.size() || S[i]!=s[lst])) lst = nxt[lst-1];
			if (S[i]==s[lst]) ++lst;
			if (lst == s.size()) ++ans; //! 匹配成功
		} cout << ans;
	}

	void print() {
		for (auto i : nxt) cout << i << ' ';
	}
};