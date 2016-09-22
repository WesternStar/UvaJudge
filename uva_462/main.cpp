#include <iostream>
#include <tuple>
using namespace std;
struct suit {
  int trump{};

  int num{};
};
enum class TRUMPS { J = 1, Q = 1 << 1, K = 1 << 2, A = 1 << 3 };

void add_trump(char a, suit &s) {
  switch (a) {
  case 'A':
    s.trump |= static_cast<int>(TRUMPS::A);
    break;
  case 'K':
    s.trump |= static_cast<int>(TRUMPS::K);
    break;
  case 'Q':
    s.trump |= static_cast<int>(TRUMPS::Q);
    break;
  case 'J':
    s.trump |= static_cast<int>(TRUMPS::J);
    break;
  }
}

int score_trump(char trump) {
  int points{};
  if (trump & static_cast<int>(TRUMPS::A)) {
    points += 4;
  }

  if (trump & static_cast<int>(TRUMPS::K)) {
    points += 3;
  }

  if (trump & static_cast<int>(TRUMPS::Q)) {
    points += 2;
  }

  if (trump & static_cast<int>(TRUMPS::J)) {
    points += 1;
  }
  return points;
}
int score_num(int num) {
  if (num < 2)
    return 2;
  else if (num == 2)
    return 1;
  else
    return 0;
}

int is_stopped(suit s) {
  bool stopped = true;
  if (s.num == 0){
    stopped = false;
  }
  if (s.trump < static_cast<int>(TRUMPS::A) and s.trump and s.num == 1) {
    stopped = false;
  }
  if (s.trump < static_cast<int>(TRUMPS::K) and s.trump and s.num == 2) {
    stopped = false;
  }
  if (s.trump < static_cast<int>(TRUMPS::Q) and s.trump and s.num == 3) {
    stopped = false;
  }
  
  return stopped;
}
int thin(suit s) {
  int dec{0};
  if (s.trump & static_cast<int>(TRUMPS::K) and s.num == 1) {
    --dec;
  }
  if (s.trump & static_cast<int>(TRUMPS::Q) and s.num <= 2) {
    --dec;
  }
  if (s.trump & static_cast<int>(TRUMPS::J) and s.num <= 3) {
    --dec;
  }
  return dec;

}

int main() {
  auto trump = [](char a) {
    return a == 'K' or a == 'Q' or a == 'A' or a == 'J';
  };
  auto score_suit = [](suit s) {
    int points = score_trump(s.trump);
    points += thin(s);
    auto stopped = is_stopped(s);
    return std::make_tuple(stopped, points, score_num(s.num));
  };

  while (cin) {

    suit clubs, hearts, diamonds, spades;
    for (int i = 0; i < 13; ++i) {
      std::string card;
      cin >> card;
      if (cin.eof()) {
        return 0;
      }
      switch (card[1]) {
      case 'C':
        clubs.num = clubs.num + 1;
        if (trump(card[0])) {
          add_trump(card[0], clubs);
        }
        break;
      case 'H':
        hearts.num = hearts.num + 1;
        if (trump(card[0])) {
          add_trump(card[0], hearts);
        }
        break;
      case 'D':
        diamonds.num = diamonds.num + 1;
        if (trump(card[0])) {
          add_trump(card[0], diamonds);
        }
        break;
      case 'S':
        spades.num = spades.num + 1;
        if (trump(card[0])) {
          add_trump(card[0], spades);
        }
        break;
      }
    }
    bool c_stopped, d_stopped, h_stopped, s_stopped;
    int c_cut, d_cut, h_cut, s_cut;
    int c_p, d_p, h_p, s_p;
    std::tie(c_stopped, c_p, c_cut) = score_suit(clubs);
    std::tie(d_stopped, d_p, d_cut) = score_suit(diamonds);
    std::tie(h_stopped, h_p, h_cut) = score_suit(hearts);
    std::tie(s_stopped, s_p, s_cut) = score_suit(spades);

    if (c_p + d_p + h_p + s_p > 16 and
        (c_stopped and d_stopped and s_stopped and h_stopped)) {
      // output no trump
      cout << "BID NO-TRUMP\n";
    } else {
      c_p += c_cut;
      d_p += d_cut;
      h_p += h_cut;
      s_p += s_cut;
      if (s_p + c_p + d_p + h_p >= 14) {
        // output bid
        cout << "BID";
        if (spades.num >= clubs.num and spades.num >= diamonds.num and
            spades.num >= hearts.num) {
          cout << " S\n";
        } else if (hearts.num >= clubs.num and hearts.num >= diamonds.num and
                   hearts.num >= spades.num) {
          cout << " H\n";
        } else if (diamonds.num >= clubs.num and diamonds.num >= spades.num and
                   diamonds.num >= hearts.num) {
          cout << " D\n";
        } else if (clubs.num >= spades.num and clubs.num >= diamonds.num and
                   clubs.num >= hearts.num) {
          cout << " C\n";
        }

      } else {
        cout << "PASS\n";
      }
    }
  }
}
