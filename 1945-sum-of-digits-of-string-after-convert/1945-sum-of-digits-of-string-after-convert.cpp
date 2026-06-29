class Solution {
public:
    int sumOfDigits(int num,int k){
        int sum=num;
        for(int i=1;i<=k;i++){
            sum=0;
            while(num!=0){
                sum=sum+num%10;
                num=num/10;
            }
            num=sum;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int val=s[i]-'a'+1;
            while(val!=0){
                sum=sum+val%10;
                val=val/10;
            }
        }
        return sumOfDigits(sum,k-1);
    }
};