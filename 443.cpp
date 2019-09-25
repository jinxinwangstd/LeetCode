class Solution {
public:
    int characterizeNum(vector<char>& chars, int num, int pos) {
        int num_digits = 1, tens = 10;
        while (num >= tens) {
            num_digits++;
            tens *= 10;
        }
        tens /= 10;
        for (int i = 1; i <= num_digits; i++) {
            char c = '0' + num % 10;
            chars[pos + num_digits - i] = c;
            num /= 10;
        }
        return num_digits;
    }
    int compress(vector<char>& chars) {
        int n = chars.size();
        char c = '\0';
        int count = 0;
        int read_ptr = 0, write_ptr = 0;
        while (read_ptr < n) {
            if (chars[read_ptr] != c) {
                c = chars[read_ptr++];
                count = 1;
            }
            while (read_ptr < n && chars[read_ptr] == c) {
                count++;
                read_ptr++;
            }
            chars[write_ptr++] = c;
            if (count > 1)
                write_ptr += characterizeNum(chars, count, write_ptr);
        }
        return write_ptr;
    }
};
