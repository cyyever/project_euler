/*
 *	程序名：euler59.cpp
 *	作者：陈源源
 *	日期：2016-03-06
 *	功能：解决eulerproject 59题(https://projecteuler.net/problem=59)
 */
#include <cinttypes>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  std::ifstream in_file(std::filesystem::path(DATA_DIR) / "p059_cipher.txt");
  vector<int> encrypted_codes;
  char encryption_key[4]{};
  unsigned char sep, plain_char;
  int encrypted_code;
  vector<string> plain_text;

  while (in_file >> encrypted_code) {
    encrypted_codes.push_back(encrypted_code);
    in_file >> sep;
  }
  if (!in_file.eof()) {
    cout << "read file failed" << endl;
    return -1;
  }

  for (encryption_key[0] = 'a'; encryption_key[0] <= 'z'; encryption_key[0]++) {
    for (encryption_key[1] = 'a'; encryption_key[1] <= 'z';
         encryption_key[1]++) {
      for (encryption_key[2] = 'a'; encryption_key[2] <= 'z';
           encryption_key[2]++) {
        string tmp;
        for (decltype(encrypted_codes.size()) i = 0; i < encrypted_codes.size();
             i++) {
          plain_char = encryption_key[i % 3] ^
                       (static_cast<unsigned char>(encrypted_codes[i]));
          tmp.push_back(plain_char);
        }
        if (tmp.find(" the ") == string::npos &&
            tmp.find(".The ") == string::npos &&
            tmp.find(" The ") == string::npos)
          continue;
        plain_text.push_back(tmp);
      }
    }
  }
  if (plain_text.size() != 1) {
    cout << "can't find plain text" << endl;
    return -1;
  }
  std::cout << plain_text[0] << std::endl;

  uint64_t code_sum = 0;
  for (auto c : plain_text[0])
    code_sum += static_cast<unsigned char>(c);
  cout << code_sum << std::endl;
  return 0;
}
