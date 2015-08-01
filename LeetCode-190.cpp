#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
      string binary = bitset<32>(n).to_string();
      string ans = reverse(binary.begin(), binary.end());
      uint32_t output = bitset<32>(ans).to_ulong();
      return output;
    }
};
