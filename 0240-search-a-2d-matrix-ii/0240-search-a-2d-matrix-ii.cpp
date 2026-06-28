class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rowIndex=0;
        int colIndex=m-1;
        while(rowIndex<n && colIndex>=0){
            int element=matrix[rowIndex][colIndex];
            if(element==target){
                return 1;
            }
            if(element<target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
    }
};