
class Solution {
public:
    int longestSubstring(std::string s, int k) {
        return longestSubstringHelper(s, k);
    }

private:
    int longestSubstringHelper(const std::string& s, int k) {
        std::unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        bool allMeetRequirement = true;
        for (const auto& pair : freq) {
            if (pair.second < k) {
                allMeetRequirement = false;
                break;
            }
        }
        
        if (allMeetRequirement) {
            return s.length();
        }

        int maxLength = 0;
        size_t start = 0;

        while (start < s.length()) {
         
            while (start < s.length() && freq[s[start]] < k) {
                start++;
            }
            
            if (start >= s.length()) break;

            size_t end = start;
            
            while (end < s.length() && freq[s[end]] >= k) {
                end++;
            }

         
            if (start < end) {
                maxLength = std::max(maxLength, longestSubstringHelper(s.substr(start, end - start), k));
            }

            start = end + 1;
        }

        return maxLength;
    }
};
