class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList){
        int m = firstList.size(),n = secondList.size();
        vector<vector<int>> intersections;
        int i=0, j=0;
        while(i<m && j<n){
            int s1 = firstList[i][0],s2 = secondList[j][0]; // start and end of firstList []
            int e1 = firstList[i][1],e2 = secondList[j][1]; // start and end of secondList []
            
            int start = max(s1, s2),end = min(e1, e2);
            if(start<=end) intersections.push_back({start,end}); // pushing intersection in []
            // 3 : choose which pointer to increment
            (e1<e2) ? i++ : j++ ;
        }
        return intersections;
    }
};