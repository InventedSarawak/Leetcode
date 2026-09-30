class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return 0;
        int sum = 1, i = 2;
        for (; i * i < num; i++) {
            if (num % i == 0) sum += (i + num / i);
        }
        if (i * i == num) sum += i;
        return (sum == num);
    }
};