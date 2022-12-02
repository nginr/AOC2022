#include <config.h>

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

#include <vector>
using std::cout;
using std::vector;


int part1(vector<int>& totalCalories, std::string file) {
    std::ifstream ifs(file);

    if (ifs.is_open()) {
        std::string line;
        char        Line[20];
        uint32_t    calorieCount = 0;
        while (ifs.good()) {
            ifs.getline(Line, 20);
            line.assign(Line);
            if (line.length() != 0) {
                calorieCount += stoi(line);
                line.clear();
            } else {
                //
                totalCalories.push_back(calorieCount);
                calorieCount = 0;
                line.clear();
            }
        }
    }

    ifs.close();
    // int index = std::distance(std::begin(totalCalories), std::max_element(totalCalories.begin(),
    // totalCalories.end())); cout << index+1 << ", " << totalCalories[index] << '\n';

    return *std::max_element(totalCalories.begin(), totalCalories.end());
}

int part2(vector<int>& totalCalories) {
    std::sort(totalCalories.begin(), totalCalories.end(), std::greater<int>());
    int top3 = 0;
    for (int i = 0; i < 3; i++) {
        top3 += totalCalories[i];
    }
    return top3;
}

int main(int argc, char* argv[]) {
    vector<int> totalCalories;

    cout << part1(totalCalories, txtst::inputFile) << '\n';
    cout << part2(totalCalories) << '\n';

    return 0;
}
