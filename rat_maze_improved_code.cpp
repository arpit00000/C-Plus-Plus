#include <iostream>
#include <vector>

class RatMazeSolver {
public:
    RatMazeSolver(const std::vector<std::vector<int>>& maze) : maze(maze), size(maze.size()) {
        solution = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void solveMaze() {
        if (findPath(0, 0)) {
            displaySolution();
        } else {
            std::cout << "No solution exists." << std::endl;
        }
    }

private:
    const std::vector<std::vector<int>>& maze;
    std::vector<std::vector<int>> solution;
    const int size;

    bool isValidMove(int row, int col) {
        return (row >= 0 && row < size && col >= 0 && col < size && maze[row][col] == 1);
    }

    bool findPath(int row, int col) {
        if (row == size - 1 && col == size - 1) {
            solution[row][col] = 1;
            return true;
        }

        if (isValidMove(row, col)) {
            solution[row][col] = 1;

            if (findPath(row, col + 1) || findPath(row + 1, col)) {
                return true;
            }

            // Backtrack
            solution[row][col] = 0;
        }

        return false;
    }

    void displaySolution() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << solution[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::vector<int>> maze = {
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };

    RatMazeSolver solver(maze);
    solver.solveMaze();

    return 0;
}
