#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vvi edges;
vi deg;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;
	edges = vvi(n, vi{});
	deg = vi(n, 0);
	while (0 < (m--)) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		edges[a].push_back(b);
		++deg[b];
	}

	auto q = queue<int>{};
	for (auto i = 0; const auto & x : deg) {
		if (0 == x) {
			q.push(i);
		}

		++i;
	}

	while (!q.empty()) {
		const auto f = move(q.front());
		q.pop();

		cout << f + 1 << ' ';
		for (const auto& b : edges[f]) {
			--deg[b];
			if (0 == deg[b]) {
				q.push(b);
			}
		}
	}

	return 0;
}