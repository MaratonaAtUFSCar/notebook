// TODO improve ranger query funtion

#define MAX -1
#define LSBit(x) (x&-x)

typedef long long ll;

/*
	- don't do add(0, j, v), add(i, 0, v), query(0, r1, l2, r2), query(l1, 0, l2, r2) !!!
	- query(l1, r1, l2, r2) -> [l1, l2], [r1, r2]
*/
struct BIT2D {
	ll ft[MAX][MAX];

	void build() {
		memset(ft, 0, sizeof ft);
	}

	void add(int i, int j, ll v) {
		for ( ; i < MAX; i += LSBit(i))
			for (int jj = j; jj < MAX; jj += LSBit(jj))
				ft[i][jj] += v;
	}

	ll query(int l1, int r1, int l2, int r2) {
		return query(l2, r2) + query(l1-1, r1-1) - query(l2, r1-1) - query(l1-1, r2);
	}

	ll query(int i, int j) {
		ll sum = 0;
		for ( ; i ; i -= LSBit(i))
			for (int jj = j; jj ; jj -= LSBit(jj))
				sum += ft[i][jj];

		return sum;
	}
};
