class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int idealSpeed = 0;
        int minSpeed = 1, maxSpeed = *max_element(piles.begin(), piles.end());

        while (minSpeed <= maxSpeed) {
            int speed = (minSpeed + maxSpeed) / 2;

            long long hoursReqd = 0;
            for (int pile: piles) {
                hoursReqd += (long)(pile + speed - 1) / speed;
            }

            if (hoursReqd <= h) {
                idealSpeed = speed;
                maxSpeed = speed - 1;
            } else minSpeed = speed + 1;
        }
        return idealSpeed;
    }
};