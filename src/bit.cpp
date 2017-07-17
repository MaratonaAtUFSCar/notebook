#define MAX -1
#define LSBit(x) (x&-x)

typedef long long ll;

/*
	- don't do add(0, v), query(0), query(0, r)
	- query(l, r) -> [l, r]
*/
struct BIT {
	ll ft[MAX];

	void build() {
		memset(ft, 0, sizeof ft);
	}

	void add(int i, ll v) {
		for ( ; i < MAX; i += LSBit(i)) ft[i] += v;
	}

	ll query(int l, int r) {
		return query(r) - query(l-1);
	}

	ll query(int i) {
		ll sum = 0;
		for ( ; i ; i -= LSBit(i)) sum += ft[i];
		return sum;
	}
};
