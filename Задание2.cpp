#include <iostream>
#include <vector>
#include <set>

bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
	if (nums.size() <= 1 || indexDiff <= 0 || valueDiff < 0) {
		return false;
	}

	std::set<long long> window;

	for (int i = 0; i < nums.size(); ++i) {
		if (i > indexDiff) {
			window.erase(nums[i - indexDiff - 1]);
		}

		auto it = window.lower_bound(static_cast<long long>(nums[i]) - valueDiff);
		if (it != window.end() && *it <= static_cast<long long>(nums[i]) + valueDiff) {
			return true;
		}

		window.insert(nums[i]);
	}

	return false;
}

int main() {

	std::vector<int> nums = { 4, 3, 7, 2, 6, 8 };
	int indexDiff = 2;
	int valueDiff = 3;
	std::cout << (containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) ? "true" : "false") << std::endl;

	return 0;
}
