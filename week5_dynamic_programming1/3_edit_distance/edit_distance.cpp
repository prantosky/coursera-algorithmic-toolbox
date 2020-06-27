#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
	int distances[str1.size() + 1][str2.size() + 1];
	int index = 0;
	while (index <= str1.size()) {
		distances[index][0] = index;
		index++;
	}
	index = 1;
	while (index <= str2.size()) {
		distances[0][index] = index;
		index++;
	}
	for (size_t i = 1; i <= str1.size(); i++) {
		for (size_t j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] != str2[j - 1]) {
				distances[i][j] = min(
					1 + distances[i - 1][j],
					min(1 + distances[i][j - 1], 1 + distances[i - 1][j - 1]));
			} else {
				distances[i][j] = distances[i - 1][j - 1];
			}
		}
	}
	return distances[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
