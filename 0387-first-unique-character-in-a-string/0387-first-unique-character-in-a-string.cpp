class Solution {
private:
    char toLowerCase(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return ch;
        }
        else{
            char temp=ch-'A'+'a';
            return temp;
        }
    }
public:
    int firstUniqChar(string s) {
        //frequency count of each other
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        //find first character with freq==1
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']==1){
                return i;//index return krna h,char nhi
            }
        }
        return -1;
    }
};