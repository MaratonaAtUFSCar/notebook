#define MAX -1

int v[MAX][MAX];
int n;

int solve() {
	int max_all = 0;
	int max_elem = -500;
	for (int i = 0; i < n*n; ++i) max_elem = max(max_elem, v[i/n][i%n]);
	if (max_elem < 0) return max_elem;

	for (int i = 0; i < n; ++i) {
		int sum[n]; memset(sum, 0, sizeof sum);

		// kadane:
		for (int j = i; j < n; ++j) {
			int max_so_far = 0, max_curr = 0;

			for (int k = 0; k < n; ++k) {
				sum[k] += v[j][k];

				max_curr = max(0, max_curr + sum[k]);
				max_so_far = max(max_so_far, max_curr);
			}
			max_all = max(max_all, max_so_far);
		}
	}
	return max_all;
}
