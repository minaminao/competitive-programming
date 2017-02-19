//2*n (n�͕ϐ��̐�) �̃O���t�����B
//i (0��i��n)�̒��_�͕ϐ�i�̃��e�����ɑΉ����An+i�̒��_�͕ϐ�i�̔ے�̃��e�����ɑΉ�����B
//x��y (x�Ȃ��y)�Ƃ������e����x,y�ɑ΂��āAx����y�ւ̕ӂ𒣂�B
//���_i�ƒ��_n+i���������A�������ɓ����Ă��� iff unsatisfiable
//�K�؂ɔ�ċA��SCC�ɂ�����StaticGraph���g�����肷�邱�ƁI

void visit(const vector<vector<int>> &g, int v,
	vector<int> &scccolor, int &colors,
	vector<int> &S, vector<char> &inS,
	vector<int> &low, vector<int> &num, int &time) {
	low[v] = num[v] = ++time;
	S.push_back(v); inS[v] = true;
	for (auto &e : g[v]) {
		int w = e;
		if (num[w] == 0) {
			visit(g, w, scccolor, colors, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		while (1) {
			int w = S.back(); S.pop_back(); inS[w] = false;
			scccolor[w] = colors;
			if (v == w) break;
		}
		colors++;
	}
}
int strongly_connected_components(const vector<vector<int>> &g, vector<int> &scccolor) {
	const int n = g.size();
	vector<int> num(n), low(n);
	vector<int> S;
	vector<char> inS(n);
	scccolor.resize(n);
	int time = 0, colors = 0;
	rep(u, 0, n) if (num[u] == 0)
		visit(g, u, scccolor, colors, S, inS, low, num, time);
	return colors;
}

bool two_satisfiability(const vector<vector<int>> &g) {
	int n = g.size() / 2;
	vector<int> scccolor;
	strongly_connected_components(g, scccolor);
	rep(i, 0, n) if (scccolor[i] == scccolor[n + i]) return false;
	return true;
}
