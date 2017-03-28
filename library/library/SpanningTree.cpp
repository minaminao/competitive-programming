#include "GraphTheory.cpp"
#include "UnionFind.cpp"

//最小全域木 (Minimum Spanning Tree)
//Kruskal O(|E|log|E|)
//非連結グラフでは最小全域森
pair<Weight, Edges> kruskal(const Graph &g) {
	int n = g.size();
	UnionFind uf(n);
	Edges es;
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			es.emplace_back(e);
	sort(es.begin(), es.end());
	Weight total = 0;
	Edges mst;
	for (auto &e : es)
		if (!uf.same(e.s, e.d)) {
			uf.unite(e.s, e.d);
			mst.push_back(e);
			total += e.w;
		}
	return make_pair(total, mst);
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235604

//最小全域木 (Minimum Spanning Tree)
//Prim O(|E|log|V|)
//root から到達可能な頂点が対象
pair<Weight, Edges> prim(const Graph &g, int root = 0) {
	int n = g.size();
	Edges mst;
	Weight total = 0;
	vector<bool> v(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.emplace(-1, root, 0);
	while (pq.size()) {
		Edge e = pq.top(); pq.pop();
		if (v[e.d])continue;
		v[e.d] = true;
		total += e.w;
		if (e.s != -1)mst.emplace_back(e);
		for (auto &f : g[e.d])
			if (!v[f.d])
				pq.emplace(f);
	}
	return make_pair(total, mst);
}