//* trie
//* 2022-04-02
class trie {
    struct node
    {
        int endcnt;
        node *son[26]; //! 26字母
    }*root;
private:
    void destroy(node *p) {
        for (auto np: p->son) if (np) destroy(np);
        delete p;
    }
public:
    trie(): root(new node) {}

    void insert(const string &s) {
        auto p(root);
        for (auto c: s) {
            auto &np = p->son[c - 'a']; //! 小写
            if (!np) np = new node;
            p = np;
        } ++p->endcnt;
    }
	
    ~trie() {
        destroy(root);
    }
};