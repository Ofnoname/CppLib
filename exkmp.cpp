class exkmp
{
	private:
		string &s;
		vector<int> z;

		auto getz() { //! s的自匹配
			z[0] = s.size();
			for (int i = 1, x = 1; i < s.size(); ++i) { //! 3456匹配，则z[3] = 3
				if (i+z[i-x] < z[x]+x) z[i] = z[i-x];
				else {
					int R = max(0, z[x] + x - i);
					while (R+i<s.size() && s[R] == s[R+i]) ++R;
					z[i] = R; x = i;
				}
			}
		}
	public:
		exkmp(auto &&_s): s(_s), z(s.size()) {
			getz();
		}
};