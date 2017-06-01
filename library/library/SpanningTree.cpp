#include "GraphTheory.cpp"
#include "UnionFind.cpp"
#include "ConnectedComponents.cpp"

//�ŏ��S��� (Minimum Spanning Tree)
//Kruskal O(|E|log|E|)
//��A���O���t�ł͍ŏ��S��X
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

//�ŏ��S��� (Minimum Spanning Tree)
//Prim O(|E|log|V|)
//root ���瓞�B�\�Ȓ��_���Ώ�
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

//�ŏ��S��L���� (minimum spanning arborescence)
//Chu-Liu/Edmonds' algorithm O(|E||V|)
Weight edmonds(const Graph &g, int root) {
	//�ӂ��t�ɒ������O���t�ōl����Ɠs��������
	int n = g.size();
	Weight total = 0;
	Graph rg = reverse(g);
	Graph rmsa;
	while (true) {
		rmsa.assign(n, Edges());
		//���_ u ����o�Ă���ŏ��R�X�g�ӂ��̗p
		Edges minout(n);
		for (int u = 0; u < n; u++) {
			if (u == root)continue;
			if (!rg[u].size())continue;
			minout[u] = *min_element(rg[u].begin(), rg[u].end());
			rmsa[u].emplace_back(minout[u]);
		}
		//�H���Ȃ���΍ŏ��S��L����
		vector<int> idx = kosaraju(rmsa);
		if (!detectCycle(idx))
			break;
		vector<int> cycle_count(n);
		Array cycle_cost(n);
		for (int u = 0; u < n; u++) {
			if (u == root)continue;
			if (!rmsa[u].size())continue;
			Edge &e = rmsa[u].front();
			if (idx[e.d] == idx[e.s]) {
				cycle_cost[idx[e.d]] += e.w;
				cycle_count[idx[u]]++;
			}
		}
		//�H�̃R�X�g�����Z
		for (int i = 0; i < n; i++)
			if (cycle_count[i] >= 2)
				total += cycle_cost[i];
		//�H���k�� �H�̑�\���_�ɕӂ𒣂蒼��
		rmsa.assign(n, Edges());
		for (auto &es : rg)
			for (auto &e : es) {
				if (idx[e.s] == idx[e.d])continue;
				//s ����o�Ă���ӂ̃R�X�g���Čv�Z
				if (cycle_count[idx[e.s]] >= 2)
					e.w -= minout[e.s].w;
				rmsa[idx[e.s]].emplace_back(idx[e.s], idx[e.d], e.w);
			}
		rg = rmsa;
	}
	for (auto &es : rmsa)
		for (auto &e : es)
			total += e.w;
	return total;
}
/*
https://en.wikipedia.org/wiki/Edmonds%27_algorithm
"A faster implementation of the algorithm due to Robert Tarjan runs in time O(ElogV) for sparse graphs and O(V^2) for dense graphs"
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2244434
*/