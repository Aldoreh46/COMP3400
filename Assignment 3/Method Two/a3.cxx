#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 #include <map>
 
using namespace std;

//------

struct card
{
  enum class suit { club, spade, diamond, heart };
  enum { ace=1, jack=10, queen=11, king=12 };
  using number = int;

  number num_;
  suit suit_;
};

bool operator ==(card const& a, card const& b)
{
  return a.num_ == b.num_ && a.suit_ == b.suit_;
}

bool operator <(card const& a, card const& b)
{
  return a.num_ < b.num_;
}

istream& operator >>(istream& is, card& c)
{
  // number followed by the suit (CSHD)...
  is >> c.num_;

  char ch;
  if (is >> ch)
  {
    switch (ch)
    {
      case 'C': c.suit_ = card::suit::club; break;
      case 'S': c.suit_ = card::suit::spade; break;
      case 'H': c.suit_ = card::suit::heart; break;
      case 'D': c.suit_ = card::suit::diamond; break;
      default:
        is.setstate(ios::failbit);
        break;
    }
  }
  else
    is.setstate(ios::badbit);
  return is;
}

ostream& operator <<(ostream& os, card const& c)
{
  os << c.num_;

  switch (c.suit_)
  {
    // card::suit allows us to access suit
    // suit::club allows us to access club
    // thus, card::suit::club lets us access club
    case card::suit::club:
      os << 'C';
      break;

    case card::suit::spade:
      os << 'S';
      break;

    case card::suit::diamond:
      os << 'D';
      break;

    case card::suit::heart:
      os << 'H';
      break;
  }

  return os;
}

//------

int main()
{
   map<card, unsigned> freqhist;
  
  card i;
  while (cin >> i)
    ++freqhist[i];

  for (auto const& elem : freqhist)
   cout<<elem.first<<" occurs "<<elem.second<<" times " << endl ;
}


