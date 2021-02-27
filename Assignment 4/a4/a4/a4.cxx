#include <deque>
#include <iterator>
#include <random>
#include <numeric>
#include <iostream>
#include "card.hxx"
#include <algorithm>

using namespace std;

using cards = std::deque<card>;

cards gen_deck_of_cards()
{
    cards retval;
    for (card_faces f(card_faces_begin), fEnd; f != fEnd; ++f)
        for (card_suits s(card_suits_begin), sEnd; s != sEnd; ++s)
            retval.push_back(card{*f, *s});
    return retval;
}

void shuffle_cards(cards &cs)
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(cs.begin(), cs.end(), gen);
}

cards draw(std::size_t num, cards &deck)
{
    auto pos = deck.begin();
    if (num <= deck.size())
    {
        advance(pos, num);
    }
    else
    {
        pos = deck.end();
    }


    cards myCard{deck.begin(), pos};

    deck.erase(deck.begin(), pos);

    return myCard;
}


ostream &operator<<(ostream &os, cards const &c)
{

    copy(c.begin(), c.end(), ostream_iterator<card>(os, " "));

    return os;
}


auto calc_score(cards const &hand) -> std::pair<std::size_t, std::size_t>
{

    size_t low = accumulate(hand.begin(), hand.end(), size_t{}, [](size_t const &sum, card const &item) {
        switch (item.face())
        {
        case card::ace:

            return sum + 1;
            break;
        case card::jack:

            return sum + 10;
            break;

        case card::queen:
        return sum+10;
        break;
        
        case card::king:
        return sum+10;
        break;

        case card::invalid:
            return sum + 0;
            break;

        default:

            return sum + item.face();
            break;
        }
    });


    size_t high = accumulate(hand.begin(), hand.end(), size_t{}, [](size_t const &sum, card const &item) {
        switch (item.face())
        {
        case card::ace:

            return sum + 11;
            break;
        case card::jack:

        return sum + 10;
        break;

        case card::queen:
        return sum+10;
        break;
        
        case card::king:
        return sum+10;
        break;

        case card::invalid:
            return sum + 0;
            break;

        default:

            return sum + item.face();
            break;
        }
    });

    return {low, high};
}

int main()
{

    cards myC;

    cards deck = gen_deck_of_cards();
    shuffle_cards(deck);

    cout << deck << " " << "\n";
    cout << '\n';
    cout << "Drawing 3 cards...\n";
    cards hand = draw(3, deck);

    cout << "Deck: "<<deck << " " << "\n";

    cout << "Hand: "<<hand << " " << "\n";


    auto result = calc_score(hand);
    if (result.first == result.second)
    {
        cout << "Score: " << result.first << "\n";
    }
    else{

        cout << "Possible Score: " << result.first << " " << result.second << "\n";
    }
}