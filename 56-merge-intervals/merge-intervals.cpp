class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort array a/c to ascending order for interval
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        // initiate a[0] as initial value
        vector<int> block = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            //check over - then find the max inteval
            if (intervals[i][0] <= block[1]) {
                // Merge overlapping intervals
                block[1] = max(block[1], intervals[i][1]);
            } else {
                // if not overlapped - push to the 2d array
                merged.push_back(block);
                block = intervals[i];
            }
        }

        merged.push_back(block);
        return merged;
    }
};