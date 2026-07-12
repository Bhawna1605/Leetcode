class Solution {
public:
    int binarySearch(vector<int>&temp,int target){
        int low=0;
        int high=temp.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(temp[mid]==target){
                return mid+1;
            }
            else if(temp[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        vector<int> ans;
        for (int x : arr) {
            ans.push_back(binarySearch(temp, x));   
        }
        return ans;
    }
};