#include <algorithm>
#include <config.h>

#include <bits/stdc++.h>

using std::cout;
using std::ifstream;
using std::string;

bool repeated(string str) {
    std::sort(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == str[i + 1]) {
            return true;
        }
    }
    return false;
}

int firstMarkerAfter(string s, int noDistinctChar) {
    for (int i = 0; i < s.length(); i++) {
        string buff = s.substr(i, noDistinctChar);
        if (!repeated(buff)) {
            return i + noDistinctChar;
        }
    }
    return -1;
}

void part1(string& s) {
    cout << firstMarkerAfter(s, 4) << '\n';
}

void part2(string& s) {
    cout << firstMarkerAfter(s, 14) << '\n';
}

int main() {
    string   input;
    ifstream ifs(txtst::inputFile);
    std::getline(ifs, input);

    part1(input);

    part2(input);
    return 0;
}
