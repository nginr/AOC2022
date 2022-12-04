#include <config.h>

#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;


struct Rucksack {
    int    length;
    string first, second, T;
};

struct Group {
    std::array<Rucksack, 3> g;
};

void loadFromFile(vector<Rucksack>& rs) {
    std::ifstream ifs(txtst::inputFile);

    if (ifs.is_open()) {
        string line;
        char   Line[256];
        while (!ifs.eof()) {
            ifs.getline(Line, 256);
            line.assign(Line);
            if (line.length() != 0) {
                int      len = line.length() / 2;
                Rucksack r;
                r.T.assign(line);
                r.length = len * 2;
                r.first = line.substr(0, len);
                r.second = line.substr(len, line.length() - 1);
                rs.push_back(r);
                line = "";
            }
        }
    }

    ifs.close();
}

void divideIntoGroups(vector<Group>& gs, vector<Rucksack>& rs) {
    for (int i = 0; i < rs.size(); i += 3) {
        Group g;
        g.g[0] = rs[i];
        g.g[1] = rs[i + 1];
        g.g[2] = rs[i + 2];
        gs.push_back(g);
    }
}

int charToPriority(char c) {
    int p = (int)c;

    if (c >= 97 && c <= 122) {
        p = p - 96;
    } else if (c >= 65 && c <= 90) {
        p = p - 64 + 26;
    }

    return p;
}

int part1(vector<Rucksack>& rs) {
    vector<int> priority;
    for (auto r : rs) {
        char e = '0';
        int  i = 0;
        while (e == '0') {
            if (r.second.find(r.first[i]) != string::npos) {
                e = r.first[i];
                priority.push_back(charToPriority(e));
            }
            i++;
        }
    }

    return std::accumulate(priority.begin(), priority.end(), 0);
}

char priorityTochar(int x) {
    if (x >= 1 && x <= 26) {
        return (char)x + 96;
    } else if (x >= 27 && x <= 52) {
        return (char)x + 64 - 26;
    }
    return '0';
}

int findBadgePriority(std::array<Rucksack, 3>& rs, int n) {
    vector<int> badge;
    int         rec[3][52] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rs[i].length; j++) {
            rec[i][charToPriority(rs[i].T[j]) - 1]++;
        }
    }
    for (int x = 0; x < 52; x++) {
        int smallest = rec[0][x];
        for (int z = 1; z < n; z++) {
            smallest = std::min(smallest, rec[z][x]);
        }
        while (smallest-- > 0) {
            badge.push_back(x + 1);
        }
    }
    return badge[0];
}

int part2(vector<Group>& gs) {
    vector<int> priority;
    for (auto g : gs) {
        priority.push_back(findBadgePriority(g.g, 3));
    }
    return std::accumulate(priority.begin(), priority.end(), 0);
}

int main(int argc, char* argv[]) {
    vector<Rucksack> rs;
    vector<Group>    gs;
    loadFromFile(rs);
    divideIntoGroups(gs, rs);

    cout << part1(rs) << '\n';
    cout << part2(gs) << '\n';
    return 0;
}
