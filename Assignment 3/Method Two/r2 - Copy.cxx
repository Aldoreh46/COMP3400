#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  // map of (number, num of times number occurs)...
  map<string, unsigned> freqhist;

  string i;
  while (cin >> i)
    ++freqhist[i];

  cout << "FreqHist results:\n";
  for (auto const& elem : freqhist)
    cout << '(' << elem.first << ',' << elem.second << ")\n";
}
