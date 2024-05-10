class Solution {
  public:
    Solution(vector<int>& w) {
      int last = 0;
      for (auto const& len : w) {
        // Generate a range of [0, w[0]} or [sum(w[0] + ... + w[i-1]), w[i]) if i is greater than 0.
        range.push_back({last, last + len});
        last += len;
      }
      srand(time(nullptr)); // use current time as seed for random generator
    }

    int pickIndex() {
      int logical_index = std::rand() % range.back().second; // Get a 0-based index in the logical array where each index is replicated by the number of its weight.
      int lo = 0, hi = range.size() - 1;
      while (lo <= hi) {
        int mid = (lo + hi)/2;
        // Check if the target logical index is within range[mid]. Each range does not include the upperbound, thus < instead of <= in the condition
        if (logical_index >= range[mid].first && logical_index < range[mid].second) {
          return mid;
        } else if (logical_index < range[mid].first) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      return -1;
    }
  private:
    vector<pair<int, int>> range;
};
