class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int bestNoDelete = arr[0];

int bestOneDelete = 0;

int ans = arr[0];

for (int i = 1; i < arr.size(); i++) {

    int prevNoDelete = bestNoDelete;

    bestNoDelete =
    max(arr[i],
        bestNoDelete + arr[i]);

    bestOneDelete =
    max(prevNoDelete,
        bestOneDelete + arr[i]);

    ans =
    max(ans,
        max(bestNoDelete,
            bestOneDelete));
}
 return ans;
        
    }
};