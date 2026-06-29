class Solution {
private:
    char toLowerCase(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
public:
    string reversePrefix(string word, char ch) {
        // string word ko lowercase mein
        for(int i = 0; i < word.length(); i++){
            word[i] = toLowerCase(word[i]);
        }
        // character ch ko lowercase mein
        ch = toLowerCase(ch);
        int index = -1;
        // ch ka first occurrence dhoondo
        for(int i = 0; i < word.length(); i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }
        // agar character nahi mila
        if(index == -1){
            return word;
        }
        // prefix reverse karo
        int start = 0;
        int end = index;
        while(start < end){
            swap(word[start], word[end]);
            start++;
            end--;
        }
        return word;
    }
};