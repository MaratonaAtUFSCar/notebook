typedef long long ll;
typedef vector<int> vi;

#define MAX -1

struct ST {
	ll st[2 * MAX];
	int n;		// array size

	void build(ll v[MAX], int s) {
		n = s;
		for (int i = 0; i < n; ++i) st[i + n] = v[i];

		for (int i = n-1; i > 0; --i) st[i] = st[i*2] + st[i*2+1];
	}

	// [l, r) / [0, n)
	ll query(int l, int r) {
		ll res = 0;
		
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) res += st[l++];
			if (r&1) res += st[--r];
		}

		return res;
	}

	void update(int p, ll value) {  // set value at position p
		for (st[p += n] = value; p > 1; p /= 2) st[p/2] = st[p] + st[p^1];
	}
};

