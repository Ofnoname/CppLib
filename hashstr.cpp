class hashstr {
    using u64 = unsigned long long;
private:
    string &s; //! 不保存原串
    vector<u64> prefix, pow;
public:
    hashstr(string &_s): s(_s) {
        u64 val(0), tpow(1);

        for(auto c: s) {
            prefix.emplace_back(val = val * 233 + c); //! ASCII码，233进制，自然溢出
            pow.emplace_back(tpow); tpow *= 233;
        }
    }
    auto hash(int l, int r) { //! 闭区间
        return l ? prefix[r] - prefix[l - 1] * pow[r - l + 1]
            	 : prefix[r];
    }
    auto hash() {
        return hash(0, s.size() - 1);
    }
};