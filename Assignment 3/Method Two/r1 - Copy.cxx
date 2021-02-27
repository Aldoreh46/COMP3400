#include <map>
#include <iostream>

using namespace std;

int main()
{
  // map of (number, num of times number occurs)...
  map<int, unsigned> freqhist;

  int i;
  while (cin >> i)
    ++freqhist[i];

  cout << "FreqHist results:\n";
  for (auto const& elem : freqhist)
    cout << '(' << elem.first << ',' << elem.second << ")\n";
}
