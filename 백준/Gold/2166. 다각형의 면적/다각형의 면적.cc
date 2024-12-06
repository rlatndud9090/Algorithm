#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int N;
vector<pair<double, double>> coords;

double calc() {
  double result = 0;
  int length = coords.size();
  for (int i = 0; i < length; i++) {
    double cur_x = coords[i].first;
    double cur_y = coords[i].second;
    double next_x = i == length - 1 ? coords[0].first : coords[i+1].first;
    double next_y = i == length - 1 ? coords[0].second : coords[i+1].second;
    result += (cur_x * next_y) - (next_x * cur_y);
  }
  return abs(result / 2.0f);
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    coords.emplace_back(x, y);
  }

  cout << fixed << setprecision(1) << calc();

  return 0;
}