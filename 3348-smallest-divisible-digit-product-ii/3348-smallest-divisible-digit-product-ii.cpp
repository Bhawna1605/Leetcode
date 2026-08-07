class Solution {
public:
    string freeSlotsFiller(long long required, int length){         
        string str;
        for(int digit=9;digit>=2;digit--){
            while(required%digit==0){
                str.push_back(digit+'0');
                required/=digit;
            }
        }
        while((int)str.length()<length){
            str.push_back('1');
        }
        reverse(begin(str),end(str));
        return str;
    }
    string smallestNumber(string num, long long t) {
        int n=num.length();
        long long temp=t;
        for(int primeFact:{2,3,5,7}){
            while(temp%primeFact==0){
                temp/=primeFact;
            }
        }
        if(temp!=1){
            return "-1";
        }
        //Precompute remainingFactor[i] = if we take i digits of num in my result, what factor remaining for t
        vector<long long>remainingFactor(n+1,t);
        for(int i=0;i<n;i++){
            int digit=num[i]-'0';
            if(digit==0){
                break;
            }
            remainingFactor[i+1]=remainingFactor[i]/gcd(remainingFactor[i],(long long)digit);
        }
        size_t zeroPosFind = num.find('0');
        bool hasZero = (zeroPosFind != string::npos);
        if(!hasZero && remainingFactor[n]==1){
            return num;
        }
        int zeroIdx = hasZero ? (int)zeroPosFind : n-1;
        for(int i=zeroIdx;i>=0;i--){
            long long required=remainingFactor[i];
            int freeSlots=n-1-i;
            for(int digit=(num[i]-'0'+1);digit<=9;digit++){
                long long furtherRequired=required/gcd(required,(long long)digit);  
                string requiredNumber=freeSlotsFiller(furtherRequired,freeSlots);
                if((int)requiredNumber.length()==freeSlots){
                    return num.substr(0,i)+char(digit+'0')+requiredNumber;
                }
            }
        }
        return freeSlotsFiller(t,n+1);
    }
};