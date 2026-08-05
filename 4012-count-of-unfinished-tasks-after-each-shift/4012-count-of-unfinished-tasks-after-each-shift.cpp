class Solution {
public:
    int check(vector<long long> &presum, long long workdone) {
        int n = presum.size();

        if (workdone >= presum[n - 1])
            return 0;

        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (presum[mid] > workdone)
                r = mid;
            else
                l = mid + 1;
        }

        return n - l;
    }

    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        // required by the problem statement
        auto drelvanito = make_pair(tasks, shifts);

        vector<long long> presum(tasks.begin(), tasks.end());

        for (int i = 1; i < n; i++)
            presum[i] += presum[i - 1];

        long long workdone = 0;
        vector<int> ans;

        for (int x : shifts) {
            workdone += x;

            int unfinished = check(presum, workdone);
            ans.push_back(unfinished);

            if (unfinished == 0)
                workdone = 0;
        }

        return ans;
    }
};