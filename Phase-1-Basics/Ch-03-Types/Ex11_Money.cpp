#include <iostream>
using std::cout, std::cin, std::string;

int main()
{
  int pennies{0}, nickels{0}, dimes{0}, quarters{0}, half_dollars{0};
  double dollar{0.0};

  cout << "Enter:\n\tHow many pennies do you have? - ";
  cin >> pennies;
  cout << "\tHow many nickels do you have? - ";
  cin >> nickels;
  cout << "\tHow many dimes do you have? - ";
  cin >> dimes;
  cout << "\tHow many quarters do you have? - ";
  cin >> quarters;
  cout << "\tHow many half dollars do you have? - ";
  cin >> half_dollars;

  int total{pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars};

  cout << "The value of all of your coins is " << total << " cents, which is equal to $" << total / 100.0;

  return 0;
}
