#include <cstdlib>
#include <string>
#include "chapter2/exceptions.h"

using namespace std;
using std::string;

class GameEntry{
  public:
    GameEntry(const string &n="", int s=0);
    string getName() const;
    int getScore() const;
  private:
    string name;
    int score;
};

GameEntry::GameEntry(const string &n="", int s=0): name(n), score(s) {}

string GameEntry::getName() const {
  return name;
};

int GameEntry::getScore() const {
  return score;
};

class Scores {
  public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry &e);
    GameEntry remove(int i) throw (IndexOutOfBounds);

  private:
    int numEntries;
    int maxEntries;
    GameEntry* entries;
};

Scores::Scores(int maxEnt=10) {
  maxEntries = maxEnt;
  numEntries = 0;
  entries = new GameEntry[maxEntries];
}

Scores::~Scores() {
  delete[] entries;
  numEntries = 0;
  maxEntries = 0;
}

void Scores::add(const GameEntry &e) {
  int newScore = e.getScore();
  if (numEntries == maxEntries && newScore <= entries[numEntries - 1].getScore()) {
    return;
  }
  int i = numEntries - 1;
  while (i >= 0 && newScore > entries[i].getScore()) {
    entries[i + 1] = entries[i];
    i--;
  }
  entries[i] = e;
  numEntries++;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
  if ((i < 0) || (i >= numEntries))
    throw IndexOutOfBounds("Invalid Index");
  GameEntry e = entries[i];
  for (int j = i + 1; j < numEntries; j++)
    entries[j - 1] = entries[j];
  numEntries--;
  return e;
}

