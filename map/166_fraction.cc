#include <map>
#include <string>
using std::map;
using std::size_t;
using std::string;
const double epsilon = 1e-6;

class Solution {
public:
  map<double, size_t> remainder_showed_up_;
  string fractionToDecimal(int numerator, int denominator) {
    string result{};
    if (numerator == 0) {
      return std::to_string(numerator);
    }
    long long temp_numerator{numerator};
    long long temp_denominator{denominator};
    unsigned long long abs_numerator = std::abs(temp_numerator);
    unsigned long long abs_denominator = std::abs(temp_denominator);
    unsigned long long integerPart = abs_numerator / abs_denominator;
    if (numerator < 0 ^ denominator < 0) {
      result += '-';
    }
    result += std::to_string(integerPart);
    unsigned long long remainder = abs_numerator % abs_denominator * 10;
    unsigned long long factor = remainder / abs_denominator;
    if (remainder == 0) {
      return result;
    } else {
      result += '.';
    }

    while (remainder > epsilon) {
      if (remainder_showed_up_.count(remainder) &&
          remainder_showed_up_.at(remainder)) {
        result.insert(result.begin() + remainder_showed_up_[remainder], '(');
        result += ')';
        break;
      } else {
        remainder_showed_up_[remainder] = result.size();
        result += std::to_string(factor);
        remainder = remainder % abs_denominator * 10;
        factor = remainder / abs_denominator;
      }
    }
    return result;
  }
};
