#include <iostream>
#include <stack>
#include <vector>

#include "Tower.h"
#include "utils.h"

size_t counterSteps{0};

void playHanoiTower(int n,
                    Tower & src,
                    Tower & help,
                    Tower & dst) {

    if (n == 1) {
        counterSteps++;
        movePiece(src, dst);
        printTowers(src, help, dst, counterSteps);
        return;
    }

    playHanoiTower(n - 1, src, dst, help);
    counterSteps++;
    movePiece(src, dst);
    printTowers(src, help, dst, counterSteps);
    playHanoiTower(n - 1, help, src, dst);
}

int main() {

    const int n{3};
    std::stack<int> srcStk;
    for (int i = n; i > 0; --i) {
        srcStk.push(i);
    }
    Tower src("src", srcStk);

    std::stack<int> helpStk;
    Tower help("help", helpStk);

    std::stack<int> dstStk;
    Tower dst("dst", dstStk);

    printTowers(src, help, dst, counterSteps);

    playHanoiTower(n, src, help, dst);

    return 0;
}
