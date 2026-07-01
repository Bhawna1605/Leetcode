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
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        //strs ko lowercase mein convert krdo
        for(int j=0;j<strs.size();j++){
            //strs k hr character ko convert krna hoga
            for(int k=0;k<strs[j].size();k++)
                strs[j][k]=toLowerCase(strs[j][k]);
        }
        string result="";
        //column by column check krna h
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            //shi h:hr string ka i-th char check kro
            if(!valid(c)){
                break;//invalid char toh ruk jao
            }
            bool allSame=true;
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size() || strs[j][i]!=c){
                    allSame=false;
                    break;
                }
            }
            if(allSame){
                result+=c;
            }
            else{
                break;
            }
        }
        return result;
    }
};