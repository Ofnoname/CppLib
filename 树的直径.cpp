#include <bits/stdc++.h>
#define long long long
using namespace std;

constexpr int MAX = 5e5 + 4;

int N;

class tree
{
	vector<pair<int, int>> to[MAX];
	void get_dis(int u, int fa, long* dis) {
		for (auto [v, w]: to[u]) if (v != fa) {
			dis[v] = dis[u] + w;
			get_dis(v, u, dis);
		}
	}
	int find_dis(int p) {
		long dis[MAX]{};
		get_dis(p, -1, dis);
		return max_element(dis, dis+N)-dis;
	}
	bool find_road(auto &vec, long &sum, int u, int des, int fa = -1) {
		if (u == des) {
			vec.push_back(u); return 1;
		}
		for (auto [v, w]: to[u]) if (v != fa) {
			if (find_road(vec, sum, v, des, u)) {
				vec.push_back(u); sum += w; return 1;
			}
		} return 0;
	}
	public:
		tree() {
			for (int i = 1; i < N; ++i) {
				int x, y, z; cin >> x >> y >> z;
				to[x].emplace_back(y, z);
				to[y].emplace_back(x, z);
			}
		}
		void getans() {
			int root = 0, p, q; long sum = 0;
			p = find_dis(root), q = find_dis(p);

			vector<int> road; find_road(road, sum, p, q); 
			printf("%lld %d\n", sum, road.size());
			for (auto u: road) printf("%d ", u);
		}
};

main() {
	// ios::sync_with_stdio(0);
	cin >> N;

	auto p = new tree; 
	p->getans();
	delete p;
}