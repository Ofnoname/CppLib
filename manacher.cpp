//* 马拉车回文算法
//* 2021-03-29
class manacher
{
	private:
		string &str, nstr;
		vector<int> f; //! 12345回文，则半径是3
	public:
		manacher(string &s, int n): str(s), nstr(n*2+1, '#'), f(n*2+1) {
			for (auto p = s.begin(), q = nstr.begin()+1; p < s.end(); ++p)
				*q = *p, q += 2;
			for (int i = 0, R = -1, x = -1; i <= n*2; ++i) {
				f[i] = (i < R) ? min(f[x*2-i], R-i) : 1;
				while (i+f[i]<=s.size()*2 && i-f[i]>=0 && nstr[i+f[i]] == nstr[i-f[i]]) f[i]++;
				if (i + f[i] > R)
					R = i + f[i], x = i;
			}
		}
		bool ispalindrome(int l, int r) {//! 左闭右开
			return f[l + r] >= r - l;
		}
};