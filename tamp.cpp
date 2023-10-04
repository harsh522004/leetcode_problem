#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert elements into the priority queue
    minHeap.push(3);
    minHeap.pop();

    int tamp = 5;
    minHeap.push(tamp);


    std::cout << minHeap.top() << std::endl;
    // The front of the queue will always be the smallest element
    

    return 0;
}
