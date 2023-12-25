#include <iostream>
#include <queue>

class MedianFinder {
private:
	std::priority_queue<int> maxHeap; 
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  

public:
	MedianFinder() {}  // класс MedianFinder	

	void addNum(int num) {
		if (maxHeap.empty() || num <= maxHeap.top()) {
			maxHeap.push(num);
		}
		else {
			minHeap.push(num);
		}

		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (minHeap.size() > maxHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		if (maxHeap.size() == minHeap.size()) {
			return (maxHeap.top() + minHeap.top()) / 2.0;
		}
		else {
			return maxHeap.top();
		}
	}
};

int main() {
	MedianFinder medianFinder;
	medianFinder.addNum(2);
	medianFinder.addNum(10);
	double result1 = medianFinder.findMedian(); // Возращает 6
	std::cout << result1 << std::endl;

	medianFinder.addNum(15);
	double result2 = medianFinder.findMedian(); // Возвращает 10
	std::cout << result2 << std::endl;

	return 0;
}