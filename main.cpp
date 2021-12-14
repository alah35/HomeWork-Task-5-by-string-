#include <iostream>
#include <string>

void findRomanNum (std::string table, char x, std::string output) {
  size_t a = table.find(x);
  size_t b = table.find('-', a);
  if (b == std::string::npos) b = table.length();
  for (int i = a + 1; i < b; i++) output += table[i];
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
      size_t a = thousands.find(arabicNum[i]);
      size_t b = thousands.find('-', a); 
      for ( int j = a + 1; j < b; j++) romeNum += thousands[j];
    } else if (i == arabicNum.length() - 3) {
      size_t a = hundreads.find(arabicNum[i]);
      size_t b = hundreads.find('-', a);
      for (int j = a + 1; j < b; j++) romeNum += hundreads[j];
    } else if (i == arabicNum.length() - 2) {
      size_t a = tens.find(arabicNum[i]);
      size_t b = tens.find('-', a);
      for (int j = a + 1; j < b; j++) romeNum += tens[j]; 
    }else if (i == arabicNum.length() - 1) {
      size_t a = units.find(arabicNum[i]);
      size_t b = units.find('-', a);
      for (int j = a + 1; j < b; j++) romeNum += units[j];
    }
  }

  std::cout << "Rome num is: " << romeNum << std::endl;
} 
