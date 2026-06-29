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
    int percentageLetter(string s, char letter) {
        //s ko lower case mein kro
        for(int i=0;i<s.length();i++){
            s[i]=toLowerCase(s[i]);
        }
        //letter ko lower case mein kro
        letter=toLowerCase(letter);
        //s ki frequency nikalo
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        //percentage nikalo
        int count=freq[letter-'a'];
        return (count*100)/s.length();
    }
};