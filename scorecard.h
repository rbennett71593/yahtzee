#include <vector>
#include <string>
//#include <algorithm>

using namespace std;

class Scorecard {

 private:
  vector<int> scores;
  int count(int, vector<int>&);
  int sum(vector<int>&);
  int rolls;

 public:
  Scorecard();
  void clear();
  int getScore(int);
  int getTotalScore();
  int getRolls();
  void incRoll();
  void resetRolls();
  void validate(int&, vector<int>);
  string printScore();

};
