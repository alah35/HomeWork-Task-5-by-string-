#include <iostream>
#include <string>

std::string findRomanNum (std::string table, char x, 
                          std::string output) {
  size_t a = table.find(x);
  size_t b = table.find('-', a);
  if (b == std::string::npos) b = table.length();
  for (int i = a + 1; i < b; i++) output += table[i];
  return output;
}

int main() {
  int num;
  std::string romeNum = "";
  std::cout << "Enter your num: ";
  std::cin >> num;
  std::string thousands = "0-1M-2MM-3MMM-",
              hundreads="0-1C-2CC-3CCC-4CD-5D-6DI-7DII-8DIII-9MC-",
              tens = "0-1X-2XX-3XXX-4XL-5L-6LX-7LXX-8LXXX-9XC-",
              units = "0-1I-2II-3III-4IV-5V-6VI-7VII-8VIII-9IX-";

  while (num < 0 || num > 3999) {
    std::cout << "Wrong number. Try again: ";
    std::cin >> num;
  }
  std::string arabicNum = std::to_string(num);

  for (int i = 0; i < arabicNum.length(); i++) {
    if (i == arabicNum.length() - 4) {
      romeNum = findRomanNum(thousands, arabicNum[i], romeNum);
    } else if (i == arabicNum.length() - 3) {
      romeNum = findRomanNum(hundreads, arabicNum[i], romeNum);
    } else if (i == arabicNum.length() - 2) {
      romeNum = findRomanNum(tens, arabicNum[i], romeNum); 
    }else if (i == arabicNum.length() - 1) {
      romeNum = findRomanNum(units, arabicNum[i], romeNum);
    }
  }

  std::cout << "Rome num is: " << romeNum << std::endl;
} 
