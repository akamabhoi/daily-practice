int findKthLargest(vector<int> &nums, int k)
{
    // Min-Heap Initialization
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto data : nums)
    {
        // We push first k elements into min-heap
        pq.push(data);
        while (pq.size() > k)
        {
            // Now, if the element at top of min-heap is smaller, we remove it and add new element
            pq.pop();
        }
    }
    // Return the top (smallest) of min-heap
    return pq.top();
}