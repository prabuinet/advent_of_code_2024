#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <unordered_map>

int main()
{
  std::ifstream ifile("input2.txt");

  std::vector<int> nums1;
  std::vector<int> nums2;

  while(!ifile.eof()) {
    int num1, num2;
    ifile >> num1 >> num2;
    nums1.push_back(num1);
    nums2.push_back(num2);
  }

  std::unordered_map<int, int> counts;
  for (auto x : nums2) {
    if (counts.find(x) == counts.end()) {
      counts[x] = 1;
    }
    else 
      counts[x]++;
  }

  long long total = 0;
  for(auto x : nums1) {
    if (counts.find(x) != counts.end())
      total += counts[x] * x;
  }

  std::cout << total << std::endl;

  return 0;
}