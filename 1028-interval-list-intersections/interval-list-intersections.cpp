class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList){
        int m = firstList.size();
        int n = secondList.size();
        vector<vector<int>> intersections;
        int i=0, j=0;

        while(i<m && j<n){
            int s1 = firstList[i][0]; // start of ith interval in FIRST array 
            int s2 = secondList[j][0]; // start of jth interval in SECOND array

            int e1 = firstList[i][1]; // end of ith interval in FIRST array
            int e2 = secondList[j][1]; // start of jth interval in SECOND array
            
            int start = max(s1, s2);
            int end = min(e1, e2);

            
            if(start<=end)// 1 : check if interval 
            {
                // 2 : find interval and push 
                intersections.push_back({start,end});
            }
            // 3 : choose which pointer to increment
            if(e1<e2){
                i++;
            }
            else{
                j++;
            }
        }
        return intersections;
    }
};