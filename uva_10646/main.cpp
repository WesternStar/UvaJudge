#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
enum class rank {
  two = 2,
  three = 3,
  four = 4,
  five = 5,
  six = 6,
  seven = 7,
  eight = 8,
  nine = 9,
  J = 10,
  Q = 10,
  K = 10,
  A = 10
};
enum class suit { CLUBS, DIAMONDS, HEARTS, SPADES };
using deck = vector<std::string>;
int main() {

  int TC{};
  cin.sync_with_stdio(false);
  int num = 1;
  for (cin >> TC; TC > 0; --TC, ++num) {
    deck cards;
    int y{};
    for (int i = 0; i < 52; ++i) {
      std::string card;
      cin >> card;
      cards.push_back(card);
    }
      std::reverse(cards.begin(),cards.end());

    auto split_deck = [](deck cards) {
      return make_tuple(deck{cards.begin(), cards.begin() + 25},
                        deck{cards.begin() + 25, cards.end()});
    };
    auto increment = [&](deck cards, int y) {
      int value;
      std::string str =cards.front();
      str[1]='\0';
      if (str[0] == 'A' or str[0] == 'K' or str[0] == 'J' or str[0] == 'Q' or str[0] == 'T') {
        y += 10;
        return make_tuple(y, deck{cards.begin() + 1, cards.end()});
      } else {
        value = std::stoi(str);
        assert(value <= 9);
        y += value;
        return make_tuple(y,
                          deck{cards.begin() + 1 + (10 - value), cards.end()});
      }
    };
    deck top{}, bottom{};
    std::tie(top, bottom) = split_deck(cards);
    int i = 0;
    std::tie(i, bottom) = increment(bottom, i);
    std::tie(i, bottom) = increment(bottom, i);
    std::tie(i, bottom) = increment(bottom, i);
    deck final_deck{top};
    final_deck.insert(final_deck.end(), bottom.begin() , bottom.end());
    cout << "Case " << num << ": " << final_deck[final_deck.size() - i] << "\n";
  }
}
