class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0, hmax = 0;
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            int hh = min(lmax, rmax);
            int hv = (r - l);
            hmax = max(hmax, hh * hv);
            if (height[l] < height[r]) {
                l++;
            } else if (height[l] > height[r]) {
                r--;
            } else {
                l++;
                r--;
            }
        }
        return hmax;
    }
};