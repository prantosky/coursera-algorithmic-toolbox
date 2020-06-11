#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int modified_binary_search(vector<std::pair<int, int>>& ranges, int start,
						   int end, int point, bool lower) {
	if (start > end) {
		if (lower) {
			return ranges.size();
		} else {
			return -1;
		}
	}

	int mid = start + (end - start) / 2;
	if (ranges[mid].first <= point and ranges[mid].second >= point) {
		if (lower) {
			return std::min(mid, modified_binary_search(ranges, start, mid - 1,
														point, lower));
		} else {
			return std::max(mid, modified_binary_search(ranges, mid + 1, end,
														point, lower));
		}
	} else if (point < ranges[mid].second) {
		return modified_binary_search(ranges, start, mid - 1, point, lower);
	} else if (point > ranges[mid].first) {
		return modified_binary_search(ranges, mid + 1, end, point, lower);
	} else {
		return -1;
	}
}

vector<int> fast_count_segments(vector<std::pair<int, int>>& ranges,
								vector<int>& points) {
	vector<int> cnt(points.size());
	std::sort(ranges.begin(), ranges.end(),
			  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
				  if (a.first == b.first) {
					  return a.second < b.second;
				  } else {
					  return a.first < b.first;
				  }
			  });

	// for (auto&& i : ranges) {
	// 	std::cout << "(" << i.first << "," << i.second << ")"
	// 			  << " ";
	// }
	// std::cout << std::endl;

	for (size_t i = 0; i < points.size(); i++) {
		auto a = modified_binary_search(ranges, 0, ranges.size() - 1, points[i],
										true);
		auto b = modified_binary_search(ranges, 0, ranges.size() - 1, points[i],
										false);
		// cout << i << " " << a << " " << b << " " << b - a + 1 << endl;
		if (a == ranges.size() or b == -1) {
			cnt[i] = 0;
		} else {
			cnt[i] = b - a + 1;
		}
	}
	return cnt;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<std::pair<int, int>> ranges(n);
	for (size_t i = 0; i < ranges.size(); i++) {
		std::cin >> ranges[i].first >> ranges[i].second;
	}

	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) { std::cin >> points[i]; }
	// use fast_count_segments
	vector<int> cnt = fast_count_segments(ranges, points);
	for (size_t i = 0; i < cnt.size(); i++) { std::cout << cnt[i] << ' '; }
}
