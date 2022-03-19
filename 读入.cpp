#ifndef FASTIN
#define BUF_SIZE  unsigned(1 << 22) //* 4MB
class Istream
{
	private:
		char buf[BUF_SIZE], *p1, *p2;
		
		char nextchar()  { //* 流中下一个字符
			return (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUF_SIZE, stdin), p1 == p2)) ? EOF : *p1++;
		}

	public:
		Istream() = default;
		Istream(const Istream&) = delete;
		Istream& operator=(const Istream&) = delete;

		template<typename T>
		void get(T &a) { //* 获取下一个整数
			a = 0;
			char ch = 0;
			bool ne = 0;
			for (;!isdigit(ch); ch=nextchar())
				if (ch == '-') ne = 1;
			for (;isdigit(ch); ch=nextchar())
				a = a*10 + (ne ? '0'-ch : ch-'0');
		}
		void get(char &a) { //* 获取下一个非空白字符
			while (isspace(a = nextchar()));
		}		
		void get(char *s) { //* 获取下一个C字符串
			char tc = 0;
			while (isspace(tc = nextchar()));
			do {
				*(s++) = tc;
			}while (!isspace(tc = nextchar()));
			*(s++) = 0;
		}
		void get(std::string &s) { //* 获取string
			char tc = 0;
			while (isspace(tc = nextchar())); 
			do {
				s += tc;
			}while (!isspace(tc = nextchar()));				
		}

		template<typename T>
		void fill(T* begin, T* end) {
			for (auto it = begin; it != end; it++)
				get(*it);
		}

		template<typename T>
		T get() {
			T ret = 0;
			get(ret);
			return ret;
		}
		template<typename T>
		Istream& operator>>(T &a) {
			get(a);
			return *this;
		}
};

Istream Cin;
#undef BUF_SIZE
#endif