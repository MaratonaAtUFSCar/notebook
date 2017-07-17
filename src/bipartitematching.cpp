#define MAX -1

int link[MAX];
bool vis[MAX];
vector<int> g[MAX];

bool solve(int curr) {
    vis[curr] = true;

    for (int next : g[curr]) {
        if (link[next] == -1) {
            link[next] = curr;
            return true;
        }
        else if (!vis[ link[next] ] && solve(link[next])) {
            link[next] = curr;
            return true;
        }
    }
    return false;
}

int max_match() {
    memset(link2, -1, sizeof link2);
    int cont = 0;

    for (int i = 0; i < n; ++i) {
        memset(vis, false, sizeof vis);
        cont += solve(i);
    }

    return cont;
}
