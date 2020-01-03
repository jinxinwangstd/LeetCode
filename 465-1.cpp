class Solution {
public:
    unordered_map<int, int> ids;
    int dfs(vector<int>& balances, int idx) {
        int n = balances.size();
        while (idx < n && balances[idx] == 0)
            idx++;
        if (idx == n)
            return 0;
        int res = INT_MAX;
        for (int i = idx + 1; i < n; i++) {
            if (balances[idx] * balances[i] < 0) {
                balances[i] += balances[idx];
                res = min(res, 1 + dfs(balances, idx + 1));
                balances[i] -= balances[idx];
            }
        }
        return res;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> balances;
        int n = transactions.size();
        for (auto& transaction : transactions) {
            int u = transaction[0], v = transaction[1], amount = transaction[2];
            if (!ids.count(u)) {
                ids[u] = balances.size();
                balances.push_back(0);
            }
            if (!ids.count(v)) {
                ids[v] = balances.size();
                balances.push_back(0);
            }
            balances[ids[u]] += amount;
            balances[ids[v]] -= amount;
        }
        return dfs(balances, 0);
    }
};

/*
 * DFS
 * After summing up all the transactions, we can have the account balance for each person.
 * For each person whose balance is not 0, we can choose the first person to take on his balance and settle his debt using one transaction.
 * Following this way, we repeatedly settle all the person's debt by choosing the first person to take on his debt in his following person and return the number of transactions we use.
 * It's basically a DFS.
 */
