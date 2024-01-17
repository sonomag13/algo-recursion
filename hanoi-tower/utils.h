//
// Created by lgao23 on 1/16/24.
//

#pragma once

#include "Tower.h"

void movePiece(Tower & src, Tower & dst) {
    int val = src.stk.top();
    src.stk.pop();
    dst.stk.push(val);
}

void printTowers(Tower tower1, Tower tower2, Tower tower3, size_t counterSteps) {

    std::vector<Tower> towers = {tower1, tower2, tower3};

    std::stack<int> src;
    std::stack<int> help;
    std::stack<int> dst;

    for (auto & tower : towers) {
        tower.reverseStack();
        if (tower.towerName == "src") {
            src = tower.reversedStk;
        }

        if (tower.towerName == "help") {
            help = tower.reversedStk;
        }

        if (tower.towerName == "dst") {
            dst = tower.reversedStk;
        }
    }

    std::stack<std::vector<int>> allTowers;

    while (!src.empty() || !help.empty() || !dst.empty()) {

        std::vector<int> level(3, 0);

        if (!src.empty()) {
            level[0] = src.top();
            src.pop();
        }

        if (!help.empty()) {
            level[1] = help.top();
            help.pop();
        }

        if (!dst.empty()) {
            level[2] = dst.top();
            dst.pop();
        }

        allTowers.push(level);
    }

    std::cout << "\nstep " << counterSteps << '\n';
    while (!allTowers.empty()) {
        auto level = allTowers.top();
        allTowers.pop();
        std::cout << "\t\t " << level[0] << "\t " << level[1] << "\t " << level[2] << '\n';
    }

    std::cout << "\t\t" << "src" << '\t' << "help" << '\t' << "dst" << '\n';

}
