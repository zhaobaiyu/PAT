#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    string::size_type a1 = 0, a2 = 0, a3 = 0;
    while (s[a1] == 'A') ++a1;
    if (s[a1] == 'P') {
      while(s[a1+1+a2] == 'A') ++a2;
      if (s[a1+1+a2] == 'T') {
        while (s[a1+a2+2+a3] == 'A') ++a3;
        if (a1+a2+a3+2 == s.size() && a2 >= 1 && a3 == a1*a2) {
          cout << "YES" << endl;
          continue;
        }
      }
    }
    cout << "NO" << endl;
  }
  return 0;
}
  /* another way, but complex
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    string::size_type pplace = 105, tplace = 105;
    bool p1 = false, t1 = false, otherch = false;
    for (string::size_type j = 0; j < s.size(); ++j) {
      if (s[j] != 'A' && s[j] != 'P' && s[j] != 'T') {
        otherch = true;
        break;
      }
      if (s[j] == 'P' && p1 == 0) {
        pplace = j;
        p1 = 1;
      }
      if (s[j] == 'T' && t1 == 0) {
        tplace = j;
        t1 = 1;
      }
    }
    if (otherch == 1 || pplace == 105 || tplace == 105 || s.size() <= 2) {
      cout << "NO" << endl;
      continue;
    }
    if (pplace == 0 && tplace == s.size() - 1) {
      if (string(s, 1, s.size() - 2) == string(s.size() - 2, 'A')) {
        cout << "YES" << endl;
        continue;
      } else {
        cout << "NO" << endl;
        continue;
      }
      //prevent tplace overflow
    } else if ((pplace == 0 && tplace != s.size() - 1) || (pplace != 0 && tplace == s.size() - 1)) {
      cout << "NO" << endl;
      continue;
    }
    if (tplace - pplace == 2) {
      if (s[pplace+1] != 'A') {
        cout << "NO" << endl;
        continue;
      }
      if (string(s, 0, pplace) == string(pplace, 'A')
          && string(s, tplace+1, s.size()-1-tplace) == string(pplace, 'A')) {
        cout << "YES" << endl;
        continue;
      } else {
        cout << "NO" << endl;
        continue;
      }
    }
    if (tplace - pplace > 2) {
      if (string(s, pplace+1, tplace-pplace-1) != string(tplace-pplace-1, 'A')) {
        cout << "NO" << endl;
        continue;
      }
      if (string(s, 0, pplace) == string(pplace, 'A')
          && string(s, tplace+1, s.size()-1-tplace) == string(pplace*(tplace-pplace-1), 'A')) {
        cout << "YES" << endl;
        continue;
      } else {
        cout << "NO" << endl;
        continue;
      }
    }
    cout << "NO" << endl;
  }
  return 0;
}
  */
