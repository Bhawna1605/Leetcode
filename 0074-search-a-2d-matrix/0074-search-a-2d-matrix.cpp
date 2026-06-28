class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();//rows
        int m=matrix[0].size();//columns
        int start=0;
        int end=n*m-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            int element=matrix[mid/m][mid%m];
            if(element==target){
                return 1;
            }
            if(element<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return 0;
    }
};