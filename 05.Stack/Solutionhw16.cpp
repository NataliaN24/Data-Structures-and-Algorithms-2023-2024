#include <iostream>
#include <stack>
#include <vector>

int maxRec(int N, const std::vector<int>& len) {
    int maxRecSurface = 0;
    std::stack<int> stack;

    for (int i = 0; i < N; i++) {
        while (!stack.empty() && len[i] < len[stack.top()]) {
            int height = len[stack.top()];
            stack.pop();
            int width = stack.empty() ? i : i - stack.top() - 1;
            maxRecSurface = std::max(maxRecSurface, height * width);
        }
        stack.push(i);
    }

    while (!stack.empty()) {
        int height = len[stack.top()];
        stack.pop();
        int width = stack.empty() ? N : N - stack.top() - 1;
        maxRecSurface = std::max(maxRecSurface, height * width);
    }

    return maxRecSurface;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int result = maxRec(N, arr);
    std::cout << result << std::endl;

    return 0;
}
