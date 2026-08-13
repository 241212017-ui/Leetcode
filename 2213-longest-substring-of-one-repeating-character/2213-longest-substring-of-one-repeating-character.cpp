class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node &L, Node &R) {

        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;

        res.len = L.len + R.len;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Initially take the best from either side
        res.best = max(L.best, R.best);

        // Prefix
        res.prefix = L.prefix;

        if (L.prefix == L.len && L.rightChar == R.leftChar) {
            res.prefix = L.len + R.prefix;
        }

        // Suffix
        res.suffix = R.suffix;

        if (R.suffix == R.len && L.rightChar == R.leftChar) {
            res.suffix = R.len + L.suffix;
        }

        // Combine suffix of L + prefix of R
        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suffix + R.prefix);
        }

        return res;
    }

    void build(int node, int start, int end) {

        if (start == end) {
            tree[node] = Node(s[start]);
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {

        if (start == end) {
            tree[node] = Node(c);
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        }
        else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};