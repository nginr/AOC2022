#include <config.h>

#include <bits/stdc++.h>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;

struct Round {
    char myMove;
    char opponentMove;

    int getScore() {
        switch (opponentMove) {
            case 'A': {
                switch (myMove) {
                    case 'X': {
                        return 3 + 1;
                    }
                    case 'Y': {
                        return 6 + 2;
                    }
                    case 'Z': {
                        return 0 + 3;
                    }
                    default:
                        break;
                }
            }
            case 'B': {
                switch (myMove) {
                    case 'X': {
                        return 0 + 1;
                    }
                    case 'Y': {
                        return 3 + 2;
                    }
                    case 'Z': {
                        return 6 + 3;
                    }
                    default:
                        break;
                }
            }
            case 'C': {
                switch (myMove) {
                    case 'X': {
                        return 6 + 1;
                    }
                    case 'Y': {
                        return 0 + 2;
                    }
                    case 'Z': {
                        return 3 + 3;
                    }
                    default:
                        break;
                }
            }
            default:
                break;
        }
        return 0;
    }

    int getActualScore() {
        switch (opponentMove) {
            case 'A': { // rock
                switch (myMove) {
                    case 'X': { // loose
                        return 0 + 3;
                    }
                    case 'Y': { // draw
                        return 3 + 1;
                    }
                    case 'Z': { // win
                        return 6 + 2;
                    }
                    default:
                        break;
                }
            }
            case 'B': { // paper
                switch (myMove) {
                    case 'X': {
                        return 0 + 1;
                    }
                    case 'Y': {
                        return 3 + 2;
                    }
                    case 'Z': {
                        return 6 + 3;
                    }
                    default:
                        break;
                }
            }
            case 'C': { // scissor
                switch (myMove) {
                    case 'X': {
                        return 0 + 2;
                    }
                    case 'Y': {
                        return 3 + 3;
                    }
                    case 'Z': {
                        return 6 + 1;
                    }
                    default:
                        break;
                }
            }
            default:
                break;
        }
        return 0;
    }
};

void loadFromFile(vector<Round>& r) {
    std::ifstream ifs(txtst::inputFile);

    if (ifs.is_open()) {
        char Line[5];
        while (!ifs.fail()) {
            ifs.getline(Line, 5);
            Round rnd;
            rnd.opponentMove = Line[0];
            rnd.myMove = Line[2];
            r.push_back(rnd);
        }
    }

    ifs.close();
}

int part1(vector<Round> r) {
    int topScore = 0;
    for (int i = 0; i < r.size(); i++) {
        topScore += r[i].getScore();
    }
    return topScore;
}

int part2(vector<Round> r) {
    int topScore = 0;
    for (int i = 0; i < r.size(); i++) {
        topScore += r[i].getActualScore();
    }
    return topScore;
}

int main(int argc, char* argv[]) {
    vector<Round> rs;
    loadFromFile(rs);

    cout << part1(rs) << '\n';
    cout << part2(rs) << '\n';
    return 0;
}
