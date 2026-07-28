class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        //frequency count
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        string mid="";
        //left half
        for(int i=0;i<26;i++){
            while(freq[i]>1){
                ans+=(char)(i+'a');
                freq[i]-=2;
            }
        }
        //Middle (if any)
        for(int i=0;i<26;i++){
            if(freq[i]==1){
                mid+=(char)(i+'a');
            }
        }
        //right half
        string rev=ans;
        reverse(rev.begin(),rev.end());
        return ans+mid+rev;
    }
};