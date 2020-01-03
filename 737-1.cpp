class UnionFind {
private:
    vector<int> p, size;
    int num;
public:
    UnionFind(int N) {
        num = N;
        p.assign(N,1);
        size.assign(N,1);
        for(int i = 0; i <N; i++) {
            p[i] = i;
        }
    }
    int findSet(int u) {
        return p[u] == u ? u : p[u] = findSet(p[u]);
    }
    bool isSameSet(int u, int v) {
        return findSet(u) == findSet(v);
    }
    void unionSet(int u, int v) {
        if(!isSameSet(u,v)) {
            int x = findSet(u), y = findSet(v);
            if(size[x] > size[y]) {
                p[y] = x;
                size[x] +=size[y];
            }
            else {
                p[x] = y;
                size[y] += size[x];
            }
            num --;
        }
        return;
    }
};

class Solution {
public:
    int num;
    map<string, int> ids;
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        num = 0;
        if(words1.size() != words2.size())
            return false;
        for(auto pair : pairs) {
            if (!ids.count(pair[0]))
                ids[pair[0]] = num++;
            if(!ids.count(pair[1]))
                ids[pair[1]] = num++;
        }
        UnionFind UF(num);
        for(auto pair:pairs) {
            UF.unionSet(ids[pair[0]], ids[pair[1]]);
        }
        int n = words1.size();
        for (int i = 0; i < n; i++) {
            if(words1[i] != words2[i] && (!ids.count(words1[i]) || !ids.count(words2[i]) || !UF.isSameSet(ids[words1[i]], ids[words2[i]])))
                return false;
        }
        return true;
    }
};

/*
 * UnionFind Set
 */
