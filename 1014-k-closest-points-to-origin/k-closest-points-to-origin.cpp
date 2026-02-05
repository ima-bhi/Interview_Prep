class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority Queue -> maxHeap
        priority_queue<pair<int, vector<int>>> pq;
        // ALWAYS REMEMBER :-Whenever a question asks for k closest or k
        // smallest or k largest it's a heap question .Though these questions
        // might be implemented using other algorithms as well but heap will
        // allow to simplify the problem as well as your code.
        // store pair in queue in max order eg :
        // points = [[3,3],[5,-1],[-2,4]], k = 2
        // 1. pq{18,{3,3}}, -- k=2
        // 2. pq {{26,{5,-1}},{18,{3,3}} --- k=2
        // 3. pq{{18,{3,3}},{20,{-2,4}}}  -- pop {26,{5,-1}} i.e k=2
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            pq.push({dist, points[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};