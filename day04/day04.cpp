#include <config.h>

#include <bits/stdc++.h>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::pair;

typedef std::pair<pair<int, int>, pair<int, int>> pii;

vector<string> splitByDelim(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<pii> loadFromFile() {
    vector<std::pair<pair<int, int>, pair<int, int>>> rng;
    std::ifstream ifs(txtst::inputFile);

    if (ifs.is_open()) {
        string line;
        char   Line[256];
        while (!ifs.eof()) {
            ifs.getline(Line, 256);
            line.assign(Line);
            if (!line.empty()) {
                vector<string> rs = splitByDelim(line, ",");
                vector<string> rs1 = splitByDelim(rs[0], "-");
                vector<string> rs2 = splitByDelim(rs[1], "-");
                pii ps;
                ps.first.first = stoi(rs1[0]);
                ps.first.second = stoi(rs1[1]);
                ps.second.first = stoi(rs2[0]);
                ps.second.second = stoi(rs2[1]);
                rng.push_back(ps);
                line = "";
            }
        }
    }
    ifs.close();
    return rng;
}


int part1(vector<pii> &rs) {
    int count = 0;
    for (auto p: rs) {
        int x = p.first.first;
        int y = p.first.second;
        int a = p.second.first;
        int b = p.second.second;

        // if (x >= a && x <= b){
        //     if (y >= a && y <= b) {
        //         count++;
        //     }
        // }
        // if (a >= x && a <= y && b >= x && b <= y) {
        //     count++;
        // }
        // cout << "[" <<  x << "-" << y << "],[" << a << "-" << b << "]\n";

        if ((x >= a && y <= b) ||
            (a >= x && b <= y)) {
            count++;
        }


    }
    return count;
}

int part2(vector<pii> &rs) {
    int count = 0;
    for (auto p: rs) {
        int x = p.first.first;
        int y = p.first.second;
        int a = p.second.first;
        int b = p.second.second;

        // if ((x < b) && (y > a)) {
        //     count++;
        // }
        if (x <= a && a <= y) {
            count++;
        }
        else if (a <= x && x <= b) {
            count++;
        }

    }
    return count;
}

int main(int argc, char* argv[]) {
    vector<pii> rs = loadFromFile();

    cout << part1(rs) << '\n';
    cout << part2(rs) << '\n';
    return 0;
}
