class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec2 is to the left of rec1
        if (rec2[3] <= rec1[1])
            return false;
        // rec2 is to the right of rec1
        if (rec2[1] >= rec1[3])
            return false;
        // rec2 is to the upper of rec1
        if (rec2[2] <= rec1[0])
            return false;
        // rec2 is to the below of rec1
        if (rec2[0] >= rec1[2])
            return false;
        // overlaping
        return true;
    }
};

/*
 * Reverse thinking
 * Considering the conditions of non-overlapping
 */
