//0-1 �z��� �A����Ԃ̌�
void solve() {
	int n; cin >> n;
	string x; cin >> x;
	int q; cin >> q;
	using P = pair<int, int>;
	enum { LEFT, RIGHT };
	//�A����Ԃ̒[�_�̏W�� �ʒu, ���[ �E�[
	set<P> st;
	/*

	a < l <= b <= r < c

	x: 1
	b �͂��ׂč폜
	a ���E�[�Ȃ獶�[ (l, LEFT) ��}��
	c �����[�Ȃ�E�[ (r, RIGHT) ��}��

	x: 0
	b �͂��ׂč폜
	a �����[�Ȃ�E�[ (l, RIGHT) ��}��
	c ���E�[�Ȃ獶�[ (r, LEFT) ��}��

	*/
	if (x.front() == '1')st.emplace(0, LEFT);
	rep(i, 1, n) {
		if (x[i - 1] == x[i])continue;
		st.emplace(i, x[i] == '0');
	}
	if (x.back() == '1')st.emplace(n, RIGHT);
	dump(st);
	rep(i, 0, q) {
		int l, r, b; cin >> l >> r >> b; l--;
		P pl(l, LEFT), pr(r, RIGHT);
		while (true) {
			auto p = st.lower_bound(pl);
			if (p == st.end())
				break;
			if (*p <= pr)
				st.erase(p);
			else
				break;
		}
		if (b == 1) {
			auto a = st.lower_bound(pl);
			if (a != st.begin()) {
				a--;
				if ((*a).second == RIGHT)
					st.emplace(l, LEFT);
			}
			else {
				st.emplace(l, LEFT);
			}
			auto b = st.upper_bound(pr);
			if (b != st.end()) {
				if ((*b).second == LEFT)
					st.emplace(r, RIGHT);
			}
			else {
				st.emplace(r, RIGHT);
			}
		}
		else {
			auto a = st.lower_bound(pl);
			if (a != st.begin()) {
				a--;
				if ((*a).second == LEFT)
					st.emplace(l, RIGHT);
			}
			auto b = st.upper_bound(pr);
			if (b != st.end()) {
				if ((*b).second == RIGHT)
					st.emplace(r, LEFT);
			}
		}
		dump(st);
		cout << st.size() / 2 << endl;
	}