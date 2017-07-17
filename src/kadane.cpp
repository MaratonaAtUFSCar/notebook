#define MAX -1

int v[MAX];
int n;

int solve() {
	int max_all = v[0];
	int max_curr = v[0];

	for (int i = 1; i < n; ++i) {
			max_curr += v[i];
			max_all = max(max_all, max_curr);
			max_curr = max(0, max_curr);
	}

	return max_all;
}
