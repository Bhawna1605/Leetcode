class Solution {
public:
    int MOD=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxEl=*max_element(begin(nums),end(nums));
        vector<vector<int>>prev(maxEl+1,vector<int>(maxEl+1,0));
        for(int first=0;first<=maxEl;first++){
            for(int second=0;second<=maxEl;second++){
                bool bothNonEmpty=(first!=0 && second!=0);
                bool gcdsMatch=(first==second);
                prev[first][second]=(bothNonEmpty && gcdsMatch)?1:0;
            }
        }
        for(int i=n-1;i>=0;i--){
            vector<vector<int>>curr(maxEl+1,vector<int>(maxEl+1,0));
            for(int first=maxEl;first>=0;first--){
                for(int second=maxEl;second>=0;second--){
                    int skip=prev[first][second];
                    int take1=prev[__gcd(first,nums[i])][second];
                    int take2=prev[first][__gcd(second,nums[i])];
                    curr[first][second]=(0LL+skip+take1+take2)%MOD;
                }
            }
            prev=move(curr);
        }
        return prev[0][0];
    }
};