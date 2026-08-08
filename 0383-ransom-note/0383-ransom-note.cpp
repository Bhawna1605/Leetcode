class Solution {
private:
    bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return 1;
        }
        return 0;
    }
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
    bool canConstruct(string ransomNote, string magazine) {
        //magazine ko lowercase mein krne k liye
        for(int j=0;j<magazine.length();j++){
            magazine[j]=toLowerCase(magazine[j]);
        }
        //ransomNote ko lowercase mein krne k liye
        for(int j=0;j<ransomNote.length();j++){
            ransomNote[j]=toLowerCase(ransomNote[j]);
        }
        //Magazine k letters count kro
        int freq[26]={0};
        for(int i=0;i<magazine.length();i++){
            if(valid(magazine[i])){
                freq[magazine[i]-'a']++;
            }
        }
        //ransomNote k hr letter ko check kro
        for(int i=0;i<ransomNote.length();i++){
            if(valid(ransomNote[i])){
                freq[ransomNote[i]-'a']--;
                if(freq[ransomNote[i]-'a']<0){
                    return 0;//letter km pd gye
                }
            }
        }
        return 1;//sb letter mile!
    }
};