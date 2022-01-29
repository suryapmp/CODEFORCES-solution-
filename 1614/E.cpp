#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int mod = 1e9 + 1;
const int N = 2e5 + 5;
int treeMN[128 * N], treeMX[128 * N], lazy[128 * N], L[128 * N], R[128 * N];
int cur;

void create_left(int node, int l, int r) {
	if (L[node] == 0) {
		int mid = (l + r) / 2;
		L[node] = ++cur;
		treeMN[L[node]] = l;
		treeMX[L[node]] = mid;
	}
}

void create_right(int node, int l, int r) {
	if (R[node] == 0) {
		int mid = (l + r) / 2;
		R[node] = ++cur;
		treeMN[R[node]] = mid + 1;
		treeMX[R[node]] = r;
	}
}
void propagate(int node, int l, int r) {
	if (lazy[node] == 0)
		return;
	treeMN[node] += lazy[node];
	treeMX[node] += lazy[node];
	if (l != r) {
		create_left(node, l, r);
		create_right(node, l, r);
		lazy[L[node]] += lazy[node];
		lazy[R[node]] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int l, int r, int T) {
	propagate(node, l, r);
	int mn = treeMN[node];
	int mx = treeMX[node];
	if (mx < T) {
		lazy[node] += 1;
		propagate(node, l, r);
		return;
	}
	if (mn > T) {
		lazy[node] -= 1;
		propagate(node, l, r);
		return;
	}
	if (mn == mx)
		return;
	int mid = (l + r) / 2;
	create_left(node, l, r);
	create_right(node, l, r);
	update(L[node], l, mid, T);
	update(R[node], mid + 1, r, T);
	treeMN[node] = min(treeMN[L[node]], treeMN[R[node]]);
	treeMX[node] = max(treeMX[L[node]], treeMX[R[node]]);
}

int query(int node, int l, int r, int idx) {
	propagate(node, l, r);
	if (l == r)
		return treeMN[node];
	int mid = (l + r) / 2;
	if (idx <= mid) {
		create_left(node, l, r);
		return query(L[node], l, mid, idx);
	} else {
		create_right(node, l, r);
		return query(R[node], mid + 1, r, idx);
	}
}

void dowork() {
	int n;
	cin >> n;
	int last_ans = 0;
	treeMN[0] = 0;
	treeMX[0] = 1e9;
	while (n--) {
		int t;
		cin >> t;
		update(0, 0, 1e9, t);
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			x = (x + last_ans) % mod;
			last_ans = query(0, 0, 1e9, x);
			cout << last_ans << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	t = 1;
//	cin >> t;
	while (t--) {
		dowork();
	}
	return 0;
}
