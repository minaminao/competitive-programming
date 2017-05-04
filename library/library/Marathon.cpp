#include "GraphTheory.cpp"
#include "SpanningTree.cpp"

//�N���X�g�t�B�[�h�̃A���S���Y�� (������)
//https://ja.wikipedia.org/wiki/����Z�[���X�}�����
//https://ja.wikipedia.org/wiki/�N���X�g�t�B�[�h�̃A���S���Y��
//http://www.prefield.com/algorithm/graph/minimum_weight_matching.html
void tmp() {
	int N, H, W;
	auto idx = [&](int i, int j) { return i*W + j; };
	vector<int> fr, fc;
	vector<vector<char>> v(H, vector<char>(W));
	Graph g1 = build(v);
	Matrix dists;
	allPairsShortestPathsByDijkstra(g1, dists);
	Graph g2(N + 1);
	rep(i, 0, N + 1)rep(j, i + 1, N + 1) {
		addEdge(g2, i, j, dists[idx(fr[i], fc[i])][idx(fr[j], fc[j])]);
	}
	auto res = kruskal(g2);
	Edges T = res.second;
	dump(T);
	vector<int> indeg(N + 1);
	for (auto &e : T)indeg[e.d]++;
	dump(indeg);
	Graph O;
}