class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        string ans;
        int carry=0;
        while(i>=0 && j>=0){
            int sum=(num1[i]-'0')+(num2[j]-'0')+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back('0'+sum);
            i--;
            j--;
        }
        while(i>=0){
            int sum=(num1[i]-'0')+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back('0'+sum);
            i--;
        }
        while(j>=0){
            int sum=(num2[j]-'0')+carry;
            carry=sum/10;
            sum=sum%10;
            ans.push_back('0'+sum);
            j--;
        }
        while(carry!=0){
            ans.push_back('0'+carry%10);
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};