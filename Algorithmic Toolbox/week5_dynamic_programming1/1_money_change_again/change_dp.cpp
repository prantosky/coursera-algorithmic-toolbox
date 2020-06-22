#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int get_change(int m) {
	vector<int> changes(m + 1);
	int c1, c3, c4;
	for (int i = 0; i <= m; i++) {
		c1 = c3 = c4 = numeric_limits<int>::max();
		if (i - 1 >= 0) {
			c1 = 1 + changes.at(i - 1);
			if (i - 3 >= 0) {
				c3 = 1 + changes.at(i - 3);
				if (i - 4 >= 0) { c4 = 1 + changes.at(i - 4); }
			}
			changes[i] = min(c1, min(c3, c4));
		} else {
			changes[i] = 0;
		}
	}
	return changes.at(m);
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
