#include <string>
#include <iostream>
using namespace std;


typedef pair<int, int> ii;

struct pairhash {
	public:
		size_t operator()(const ii &x) const {
			return (x.first << 32) ^ x.second;
		}
};

unordered_map<ii, int, pairhash> rules;

int main () {
	hash<string> hasher;

	size_t h = hasher("test");
	cout << h << endl;

	return 0;
}
