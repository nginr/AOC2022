#include <config.h>

#include <bits/stdc++.h>

using std::cout;
using std::ifstream;
using std::list;
using std::string;
using std::vector;
#define NEWLINE cout << std::endl

void printCargo(vector<list<char>>& cargo) {
    for (auto c : cargo) {
        for (auto it = c.cbegin(); it != c.cend(); ++it)
            cout << *it << ", ";
        NEWLINE;
    }
}

void printTopStack(vector<list<char>>& cargo) {
    for (auto v : cargo)
        cout << v.back();
    NEWLINE;
}

vector<string> splitByDelim(string s, string delimiter) {
    size_t         pos_start = 0, pos_end, delim_len = delimiter.length();
    string         token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

vector<list<char>> readDrawing(ifstream& ifs) {
    int cargoChar = 4;

    vector<list<char>> cargo(10);
    for (string line; line[1] != '1'; std::getline(ifs, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (!isalpha(line[i])) continue;
            int CargoStack = (i - 1) / cargoChar;
            cargo[CargoStack].push_front(line[i]);
        }
    }
    return cargo;
}

struct instruction {
    int amount, from, to;
};

vector<instruction> loadFromFile(ifstream& ifs) {
    vector<instruction> ics;
    for (string line; std::getline(ifs, line);) {
        if (line.empty()) {
            continue;
        }
        vector<string> words = splitByDelim(line, " ");
        instruction    i;
        i.amount = stoi(words[1]);
        i.from = stoi(words[3]);
        i.to = stoi(words[5]);
        ics.push_back(i);
    }
    return ics;
}

void executeInstruction9000(vector<list<char>>& cargo, instruction& i) {
    int n = i.amount;
    int indxF = i.from - 1;
    int indxT = i.to - 1;
    for (int i = 0; i < n; i++) {
        char tmp = cargo[indxF].back();
        cargo[indxT].push_back(tmp);
        cargo[indxF].pop_back();
    }
}

void part1(vector<list<char>>& cargo, vector<instruction>& ic) {
    for (auto i : ic)
        executeInstruction9000(cargo, i);

    printTopStack(cargo);
}

void executeInstruction9001(vector<list<char>>& cargo, instruction& i) {
    int n = i.amount;
    int indxF = i.from - 1;
    int indxT = i.to - 1;

    list<char> tmp;

    list<char>::iterator it;
    it = cargo[indxF].end();
    it--;
    for (int i = 0; i < n; i++) {
        tmp.push_front(*it);
        --it;
        cargo[indxF].pop_back();
    }
    it = cargo[indxT].end();
    cargo[indxT].splice(it, tmp);
}

void part2(vector<list<char>>& cargo, vector<instruction>& ic) {
    for (auto i : ic)
        executeInstruction9001(cargo, i);
    printTopStack(cargo);
}

int main() {
    ifstream            ifs(txtst::inputFile);
    vector<list<char>>  cargo = readDrawing(ifs);
    vector<instruction> ic = loadFromFile(ifs);
    ifs.close();
    part1(cargo, ic);
    ifs.open(txtst::inputFile);
    cargo = readDrawing(ifs);
    ifs.close();
    part2(cargo, ic);
    return 0;
}
