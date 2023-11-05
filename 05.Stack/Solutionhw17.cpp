#include <iostream>
#include <list>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::list<int> playerScores;
    std::vector<std::list<int>::iterator> survivors;

    for (int i = 0; i < n; ++i) {
        int score;
        std::cin >> score;
        playerScores.push_back(score);
    }

    bool hasFinalists = true;
    auto current = playerScores.end();

    while (current != playerScores.begin()) {
        --current;
        auto previous = current;
        --previous;

        if (previous != playerScores.end() && *current > *previous) {
            if (!survivors.empty() && current == survivors.back()) {
                survivors.pop_back();
            }

            survivors.push_back(previous);

            auto prev = current;
            --prev;
            playerScores.erase(current);
            current = prev;
            ++current;

            hasFinalists = false;
        }
    }

    if (hasFinalists) {
        std::cout << 0;
        return 0;
    }

    int daysUntilFinal = 1;
    bool isEliminated = false;

    for (int i = 0; i < survivors.size(); i++) {
        auto currentFighter = survivors[i];
        auto nextFighter = currentFighter;
        ++nextFighter;

        if (nextFighter != playerScores.end() && *currentFighter < *nextFighter) {
            if (survivors.size() > 1 && i >= 1 && nextFighter == survivors[i - 1]) {
                i--;
                survivors.erase(survivors.begin() + i);
            }

            playerScores.erase(nextFighter);
            isEliminated = true;
        }

        if (survivors.size() - 1 == i) {
            if (isEliminated) {
                daysUntilFinal++;
                isEliminated = false;
                i = -1;
            } else {
                break;
            }
        }
    }

    std::cout << daysUntilFinal;

    return 0;
}
