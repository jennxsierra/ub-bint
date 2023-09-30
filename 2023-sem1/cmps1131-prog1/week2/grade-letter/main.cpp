#include <iostream>

using namespace std;

int main ()
{
  double avg;

  cout << "Enter the student's average: ";
  cin >> avg;

  if (avg >= 90)
    {
      cout << "\nYour grade is A.";
    }
  else if (avg >= 80)
    {
      cout << "\nYour grade is B.";
    }
  else if (avg >= 70)
    {
      cout << "\nYour grade is C.";
    }
  else
    {
      cout << "\nYour grade is F.";
    }

  return 0;
}