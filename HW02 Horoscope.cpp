// Semi Kim
// ITP 165, 2024 spring
// Homework 02 Horoscope

#include <iostream>

int main() {
  
  int month = 0;
  int day = 0;
  std::string horoscope;
  
  std::cout << "Welcome to your horoscope.\n";

  std::cout << "Enter your birth month as a number: ";
  std::cin >> month;

  std::cout << "Enter your birth day on which you were born: ";
  std::cin >> day;

  if (month == 4) {
    if (day > 19) {
      std::cout << "Your sign is Taurus.\n";
      horoscope = "Plans will take shape!";
    }
    else {
      std::cout << "Your sign is Aries.\n";
      horoscope = "Move forward confidently!";
    }
  }

  else if (month == 5) {
    if (day > 20) {
      std::cout << "Your sign is Gemini.\n";
      horoscope = "Career and business will see progress!";
    }
    else {
      std::cout << "Your sign is Taurus.\n";
      horoscope = "Plans will take shape!";
    }
  }
    
  else if (month == 6) {
    if (day > 20) {
      std::cout << "Your sign is Cancer.\n";
      horoscope = "Your personality will improve!";
    }
    else {
      std::cout << "Your sign is Gemini.\n";
      horoscope = "Career and business will see progress!";
    }
  }
    
  else if (month == 7) {
    if (day > 22) {
      std::cout << "Your sign is Leo.\n";
      horoscope = "Move forward swiftly!";
    }
    else {
      std::cout << "Your sign is Cancer.\n";
      horoscope = "Your personality will improve!";
    }
  }
    
  else if (month == 8) {
    if (day > 22) {
      std::cout << "Your sign is Virgo.\n";
      horoscope = "Maintain harmony in relationships!";
    }
    else {
      std::cout << "Your sign is Leo.\n" << "Horoscope for Leo is: \n";
      horoscope = "Move forward swiftly!";
    }
  }

  else if (month == 9) {
     if (day > 22) {
       std::cout << "Your sign is Libra.\n" << "Horoscope for Libra is: \n";
        horoscope = "Progress in career and business will continue!";
     }
    else {
      std::cout << "Your sign is Virgo.\n" << "Horoscope for Virgo is: \n";
      horoscope = "Maintain harmony in relationships!";
    }
  }
    
  else if (month == 10) {
    if (day > 22) {
      std::cout << "Your sign is Scorpio.\n" << "Horoscope for Scorpio is: \n";
      horoscope = "Overall positivity will lead to gains!";
    }
    else {
      std::cout << "Your sign is Libra.\n" << "Horoscope for Libra is: \n";
      horoscope = "Progress in career and business will continue!";
    }
  }

  else if (month == 11) {
    if (day > 21) {
      std::cout << "Your sign is Sagittarius.\n" << "Horoscope for Sagittarius is: \n";
      horoscope = "Your self-confidence will remain high!";
    }
    else {
      std::cout << "Your sign is Scorpio.\n" << "Horoscope for Scorpio is: \n";
      horoscope = "Overall positivity will lead to gains!";
    }
  }

  else if (month == 12) {
    if (day > 21) {
      std::cout << "Your sign is Capricorn.\n";
      horoscope = "Discipline and patience will yield results!";
    }
    else {
      std::cout << "Your sign is Sagittarius.\n";
      horoscope = "Your self-confidence will remain high!";
    }
  }

  else if (month == 1) {
    if (day > 19) {
      std::cout << "Your sign is Aquarius.\n";
      horoscope = "Business and career will prosper!";
    }
    else {
      std::cout << "Your sign is Capricorn.\n";
      horoscope = "Discipline and patience will yield results!";
    }
  }

  else if (month == 2) {
    if (day > 18) {
      std::cout << "Your sign is Pisces.\n";
      horoscope = "You will move ahead with preparation!";
    }
    else {
      std::cout << "Your sign is Aquarius.\n";
      horoscope = "Business and career will prosper!";
    }
  }

  else if (month == 3) {
    if (day > 20) {
      std::cout << "Your sign is Aries.\n";
      horoscope = "Move forward confidently!";
    }
    else {
      std::cout << "Your sign is Pisces.\n";
      horoscope = "You will move ahead with preparation!";
    }
  }

std::cout << "Your horoscope is: " << horoscope << "\n";
std::cin >> horoscope;

return 0;
}