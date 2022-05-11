auto pow(auto a, auto b, auto mod) {
	decltype(a) ans(1);

	a %= mod;
	while (b) {
		if (b & 1) (ans *= a) %= mod;
		(a *= a) %= mod;
	} return ans;
}