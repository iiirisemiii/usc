// Semi Kim
// ITP 165, 2024 spring
// Homework 03 Mortgage

#include <iostream>
#include <iomanip>

int main() {
  int month = 0;
  float housePrice;
  float downPayment;
  float interestRate;
  float payment;
  float interest = 0;
  float insurance = 0;
  float principle = 0;

  // get user input
  std::cout << "Mortgage Payment Schedule\n";
  std::cout << "Enter house price: ";
  std::cin >> housePrice;
  std::cout << "Enter down payment: ";
  std::cin >> downPayment;
  std::cout << "Enter interest rate(%): ";
  std::cin >> interestRate;
  interestRate /= 100;
  std::cout << "Enter monthly payment: ";
  std::cin >> payment;
  principle = housePrice - downPayment;
  std::cout << std::fixed << std::setprecision(2);

  // print out the header of a table
  std::cout << std::setw(5)  << "month" << ":" << std::setw(10) << "principle" << " +" << std::setw(10) << "interest" << " +" << std::setw(10) << "insurance" << " -" << std::setw(10) << "payment" << " =" << std::setw(10) << " new principle" << "\n";

  // loop until the new principle is bigger than 0
  while (principle + interest + insurance - payment > 0)
    {
      month += 1;
      interest = principle * interestRate / 12;
      // if the insurance is owed
      if (principle > 0.8 * housePrice)
      {
        insurance = principle * 0.005 / 12;
      }
      else
      {
        insurance = 0;
      }
      
      // if the new principle is smaller than the previous principle
      if (interest + insurance - payment <= 0)
        {
          std::cout << std::setw(5) << month << ":" << std::setw(10) << principle << " +" << std::setw(10) << interest << " +" << std::setw(10) << insurance << " -" << std::setw(10) << payment << " =" << std::setw(10) << principle + interest + insurance - payment << "\n";
          principle = principle + interest + insurance - payment;
        }
      // if the new principle is larger than the previous principle
      else
      {
        std::cout << std::setw(5) << month << ":" << std::setw(10) << principle << " +" << std::setw(10) << interest << " +" << std::setw(10) << insurance << " -" << std::setw(10) << payment << " =" << std::setw(10) << principle + interest + insurance - payment << "\n";
        std::cout << "payment is not enough, loan will never get paid";
        break;
      }
    }
  
  // if the new principle is bigger than 0
  if (principle + interest + insurance - payment <= 0)
  {
    month += 1;
    interest = principle * interestRate / 12;
    std::cout << std::setw(5) << month << ":" << std::setw(10) << principle << " +" << std::setw(10) << interest << " +" << std::setw(10) << insurance << " -" << std::setw(10) << principle + interest << " =" << std::setw(10) << "0\n";
  }
  return 0;
}