//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//template<typename Arc>
//struct StaticGraph {
//	typedef pair<int, Arc> Edge;
//
//	struct ArcList {
//		ArcList() : arcBegin(), arcEnd() {}
//		ArcList(const Arc *arcBegin, const Arc *arcEnd) : arcBegin(arcBegin), arcEnd(arcEnd) {}
//
//		const Arc *begin() const { return arcBegin; }
//		const Arc *end() const { return arcEnd; }
//		int size() const { return (int)(arcEnd - arcBegin); }
//		bool empty() const { return arcBegin == arcEnd; }
//		Arc operator[](int i) const { return arcBegin[i]; }
//
//	private:
//		const Arc * const arcBegin, *const arcEnd;
//	};
//
//	int size() const { return (int)offsets.size() - 1; }
//
//	ArcList operator[](int i) const {
//		return ArcList(arcs.data() + offsets[i], arcs.data() + offsets[i + 1]);
//	}
//
//	void init(int n, const vector<Edge> &edges) {
//		int m = (int)edges.size();
//		arcs.resize(m + 1);
//		offsets.assign(n + 1, 0);
//		for (int ei = 0; ei < m; ++ei)
//			++offsets[edges[ei].first];
//		for (int i = 0; i < n; ++i)
//			offsets[i + 1] += offsets[i];
//		for (int ei = m - 1; ei >= 0; --ei)
//			arcs[--offsets[edges[ei].first]] = edges[ei].second;
//	}
//
//
//	vector<Arc> arcs;
//	vector<int> offsets;
//};
//
//struct Food {
//	int F;
//	int D;
//	Food() : F(0), D(0) {}
//
//	int getTrueScoreAt(int t) const {
//		return F - D * t;
//	}
//
//	bool exists() const {
//		return F != 0 || D != 0;
//	}
//};
//
//const int MaxV = 2500;
//array<uint64_t, MaxV> hashKeys;
//struct State {
//	double perturbatedScore;
//	int trueScore;
//	bitset<MaxV> visited;
//	int currentVertex;
//	shared_ptr<State> parent;
//	uint64_t hash;
//	State() {}
//	explicit State(int startVertex) :
//		perturbatedScore(0), trueScore(0), currentVertex(startVertex),
//		hash(startVertex) {
//	}
//	State(const shared_ptr<State> &s, int newVertex) :
//		perturbatedScore(s->perturbatedScore), trueScore(s->trueScore), visited(s->visited), currentVertex(newVertex),
//		parent(s), hash(s->hash - s->currentVertex + newVertex) {
//	}
//
//	void visit(int u) {
//		assert(!visited[u]);
//		visited[u] = true;
//		hash += hashKeys[u];
//	}
//
//	uint64_t getHash() const {
//		return hash;
//	}
//};
//
//
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//#if defined(MY_LOCAL_RUN) && 1
//	freopen("C:/test/sagyo/B-in-1.txt", "r", stdin);
//	freopen("C:/test/sagyo/B-out.txt", "w", stdout);
//#endif
//	{
//		mt19937_64 re;
//		rep(i, 0, MaxV)
//			hashKeys[i] = re();
//	}
//	chrono::high_resolution_clock clk;
//	int H; int W; int K;
//	while (~scanf("%d%d%d", &H, &W, &K)) {
//		auto startTime = clk.now();
//		int startY; int startX;
//		scanf("%d%d", &startY, &startX), --startY, --startX;
//		vector<bool> blocked(H * W);
//		rep(i, 0, H) {
//			char buf[101];
//			scanf("%s", buf);
//			rep(j, 0, W)
//				blocked[i * W + j] = buf[j] == '#';
//		}
//		StaticGraph<int> graph;
//		{
//			vector<StaticGraph<int>::Edge> edges;
//			rep(i, 0, H) rep(j, 0, W) if (!blocked[i * W + j]) {
//				static const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
//				for (int d = 0; d < 4; ++d) {
//					int yy = i + dy[d], xx = j + dx[d];
//					if (yy < 0 || yy >= H || xx < 0 || xx >= W) continue;
//					if (blocked[yy * W + xx]) continue;
//					edges.emplace_back(i * W + j, yy * W + xx);
//				}
//			}
//			graph.init(H * W, edges);
//		}
//		int N;
//		scanf("%d", &N);
//		vector<Food> foods(H * W, Food());
//		rep(i, 0, N) {
//			int y; int x; int F; int D;
//			scanf("%d%d%d%d", &y, &x, &F, &D), --y, --x;
//			Food &f = foods[y * W + x];
//			f.F += F;
//			f.D += D;
//		}
//
//		auto getMoves = [W, K](const State &state) {
//			vector<int> path;
//			for (const State *s = &state; ; s = s->parent.get()) {
//				path.push_back(s->currentVertex);
//				if (!s->parent) break;
//			}
//			reverse(path.begin(), path.end());
//			assert(!path.empty() && path.size() <= (size_t)K + 1);
//			int lastVertex = path.back();
//			path.resize(K + 1, lastVertex);
//			string moves;
//			rep(k, 0, K) {
//				int u = path[k], v = path[k + 1];
//				if (u == v) {
//					moves += '-';
//					continue;
//				}
//				int i = u / W, j = u % W;
//				static const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
//				for (int d = 0; d < 4; ++d) {
//					int yy = i + dy[d], xx = j + dx[d];
//					if (yy * W + xx == v)
//						moves += "RDLU"[d];
//				}
//			}
//			assert(moves.size() == K);
//			return moves;
//		};
//		int bestMoveScore = 0;
//		string bestMoves;
//		mt19937 re;
//		for (int iter = 0; ; ++iter) {
//			if (chrono::duration_cast<chrono::milliseconds>(clk.now() - startTime).count() > 9000)
//				break;
//			vector<double> randomMultiplier(H * W, 1);
//			{
//				normal_distribution<double> dist(1.0, 0.05);
//				rep(i, 0, H * W) if (foods[i].exists())
//					randomMultiplier[i] = dist(re);
//			}
//			const int beamSize = 100;
//			vector<shared_ptr<State>> que;
//			vector<State> nque;
//			unordered_map<uint64_t, double> hashMap;
//			State bestState(startY * W + startX);
//			hashMap[bestState.getHash()] = 0;
//			nque.push_back(bestState);
//			double prevMaxScore = 0;
//			int lastMaxScoreT = 0;
//			for (int t = 0; t <= K; ++t) {
//				if (nque.empty()) break;
//				{
//					double maxScore = -INF;
//					for (auto &&s : nque)
//						chmax(maxScore, s.perturbatedScore);
//					//cerr << t << ": " << maxScore << endl;
//					if (prevMaxScore >= maxScore) {
//						if (t - lastMaxScoreT >= 50)
//							break;
//					}
//					else {
//						lastMaxScoreT = t;
//					}
//					prevMaxScore = maxScore;
//				}
//				if (nque.size() > (size_t)beamSize) {
//					double coeff = max(1., t * 1. / 100);
//					auto getScore = [t, coeff](const State &a) -> double {
//						return a.perturbatedScore * coeff + a.trueScore * (1 - coeff);
//					};
//					nth_element(nque.begin(), nque.begin() + beamSize, nque.end(),
//						[getScore](const State &a, const State &b) {
//						return getScore(a) > getScore(b);
//					});
//					nque.resize(beamSize);
//				}
//				que.clear();
//				for (auto &&s : nque) {
//					if (hashMap[s.getHash()] == s.trueScore)
//						que.push_back(make_shared<State>(s));
//				}
//				nque.clear();
//				for (auto &&state : que) {
//					for (int newVertex : graph[state->currentVertex]) {
//						State newState(state, newVertex);
//						if (!state->visited[newVertex] && foods[newVertex].exists()) {
//							newState.visit(newVertex);
//							int score = foods[newVertex].getTrueScoreAt(t);
//							newState.trueScore += score;
//							newState.perturbatedScore += score * randomMultiplier[newVertex];
//						}
//						if (bestState.trueScore < newState.trueScore)
//							bestState = newState;
//						{
//							auto it = hashMap.emplace(make_pair(newState.getHash(), -INF)).first;
//							if (newState.trueScore <= it->second)
//								continue;
//							it->second = newState.trueScore;
//						}
//						nque.push_back(std::move(newState));
//					}
//				}
//			}
//#ifdef MY_LOCAL_RUN
//			cerr << iter << ": " << bestState.trueScore << endl;
//			//cerr << getMoves(bestState).substr(0, 200) << endl;
//#endif
//			if (bestMoveScore < bestState.trueScore) {
//				bestMoveScore = bestState.trueScore;
//				bestMoves = getMoves(bestState);
//			}
//		}
//#ifdef MY_LOCAL_RUN
//		cerr << "best: " << bestMoveScore << endl;
//#endif
//		puts(bestMoves.c_str());
//	}
//	return 0;
//}