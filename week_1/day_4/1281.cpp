class Solution {
public:
  int subtractProductAndSum(int n) {
    int sumDigits = 0, productDigits = 1;
    while (n > 0) {
      sumDigits += n % 10;
      productDigits *= n % 10;
      n /= 10;
    }
    return (sumDigits - productDigits - sumDigits);
  }
};
