class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());//same values ek sath aa jayengi
        vector<int>counts;//har distinct value ki frequency
        int i=0;
        while(i<arr.size()){
            int count=0;
            int j=i;
            while(j<arr.size() && arr[j]==arr[i]){
                count++;
                j++;
            }
            counts.push_back(count);
            i=j;//next distinct value pr jump
        }
        //ab counts ko sort krke adjacent duplicates check kro
        sort(counts.begin(),counts.end());
        for(int k=0;k+1<counts.size();k++){
            if(counts[k]==counts[k+1]){
                return false;
            }
        }
        return true;
    }
};