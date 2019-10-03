class Solution {
public:
    string codes[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> record;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            string morse;
            for (char c : word)
                morse.append(codes[c - 'a']);
            record.insert(morse);
        }
        return record.size();
    }
};
