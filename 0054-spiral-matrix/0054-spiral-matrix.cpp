class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();      // rows
        int m = matrix[0].size();   // columns
        int count = 0;
        int total = n * m;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n - 1;
        int endingCol = m - 1;
        while (count < total) {
            // Print Starting Row
            for (int index = startingCol; count < total && index <= endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            // Print Ending Column
            for (int index = startingRow; count < total && index <= endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            // Print Ending Row
            for (int index = endingCol; count < total && index >= startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            // Print Starting Column
            for (int index = endingRow; count < total && index >= startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};