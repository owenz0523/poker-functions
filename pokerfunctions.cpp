#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

//  check pair
bool checkPair(vector<int> cardNums) {
  for (int i=0; i < 2; i++) {
    for (int j=2; j < 7; j++) {
      if (cardNums[i] == cardNums[j]) {
        return true;
      }
    }
  }
  return false;
}

// check two pair
bool checkTwoPair(vector<int> cardNums) {
  for (int i=1; i < 7; i++) {
    if (cardNums[0] == cardNums[i]) {
      for (int j=2; j < 7; j++) {
      if (cardNums[1] == cardNums[j]) {
        return true;
      }
    }
    }
  }
  return false;
}

// check three kind
bool checkThreeKind(vector<int> cardNums) {
  for (int i=0; i < 2; i++) {
    int frequency = 0;
    for (int j=i; j < 7; j++) {
      if (cardNums[i] == cardNums[j]) {
        frequency++;
      }
      if (frequency == 3) {
        return true;
      }
    }
  }
  return false;
}

// check straight
bool checkStraight(vector<int> cardNums) {
  sort (cardNums.begin(), cardNums.end());
  for (int i=0; i < 3; i++) {
    int frequency = 1;
    for (int j=i; j < i+4; j++) {
      if (cardNums[j] == cardNums[j+1] - 1) {
        frequency++;
      if (frequency == 5) {
        return true;
      }
      }
    }
  }
  return false;
}

// check flush
bool checkFlush(vector<string> cardSuits) {
  for (int i=0; i < 2; i++) {
    int frequency = 0;
    for (int j=i; j < 7; j++) {
      if (cardSuits[i] == cardSuits[j]) {
        frequency++;
        if (frequency == 5) {
          return true;
        }
      }
    }
  }
  return false;
}

// check full house
bool checkFullHouse(vector<int> cardNums) {
  int frequency = 0;
  for (int i=0; i < 7; i++) {
    if (cardNums[0] == cardNums[i]) {
      frequency++;
    }
  }
  for (int j=1; j < 7; j++) {
    if (cardNums[1] == cardNums[j]) {
      frequency++;
      if (frequency == 5) {
        return true;
      }
    }
  }
  return false;
}

// check four kind
bool checkFourKind(vector<int> cardNums) {
  for (int i=0; i < 2; i++) {
    int frequency = 0;
    for (int j=i; j < 7; j++) {
      if (cardNums[i] == cardNums[j]) {
        frequency++;
        if (frequency == 4) {
        return true;
        }
      }
    }
  }
  return false;
}


int main() {
  // open file and parse data
  fstream newfile;
  newfile.open("card-data-3.txt",ios::in);
  vector<int> cardNums = {};
  vector<string> cardSuits = {};
   if (newfile.is_open()) {
      string card;
      while (getline(newfile, card)) {
        int index = card.find(":");
        cardNums.push_back(stoi(card.substr(0, index)));
        cardSuits.push_back(card.substr(index + 1, card.length() - 2));
      }
    }

  newfile.close();

  // output results
  if (checkFourKind(cardNums)) {
    cout << "Hand returned four of a kind!" << endl;
  } else if (checkFullHouse(cardNums)) {
    cout << "Hand returned full house!" << endl;
  } else if (checkFlush(cardSuits)) {
    cout << "Hand returned flush!" << endl;
  } else if (checkStraight(cardNums)) {
    cout << "Hand returned straight!" << endl;
  } else if (checkThreeKind(cardNums)) {
    cout << "Hand returned three of a kind!" << endl;
  } else if (checkTwoPair(cardNums)) {
    cout << "Hand returned two pair!" << endl;
  } else if (checkPair(cardNums)) {
    cout << "Hand returned pair!" << endl;
  } else {
    cout << "Hand was bad :(" << endl;
    }

}