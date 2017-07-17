#define MAX -1
#define LSBit(x) (x&-x)

typedef long long ll;

/*
	- don't do update(0, r, by), query(0), query(0, r)
	- query(l, r) -> [l, r]
*/
struct BIT {
	ll add[MAX];
	ll mul[MAX];

	void build() {
		memset(add, 0, sizeof add);
		memset(mul, 0, sizeof mul);
	}

	void internalUpdate(int i, ll mu, ll ad) {
		for ( ; i < MAX; i += LSBit(i)) {
			add[i] += ad;
			mul[i] += mu;
		}
	}

	void update(int l, int r, ll by) {
		internalUpdate(l, by, -by * (l - 1));
		internalUpdate(r, -by, by * r);
	}

	ll query(int l, int r) {
		return query(r) - query(l-1);
	}
	
	ll query(int i) {
		ll mu = 0, ad = 0;

		int start = i;

		for ( ; i; i -= LSBit(i) ) {
			mu += mul[i];
			ad += add[i];
		}
		return mu * start + ad;
	}
};
