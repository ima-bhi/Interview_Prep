class Solution {
public:
    bool isAnagram(string s, string t) {
        // check if size not equal return false
        if (s.size()!=t.size()) return false;
        // map for stored frequency as per s and t--
        unordered_map <char, int> umap;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
            umap[t[i]]--;
        }

        //if any element - freq > 0 return false
        for (auto it: umap) {
            if (it.second) return false;
        }
        // default true
        return true;
    }
};