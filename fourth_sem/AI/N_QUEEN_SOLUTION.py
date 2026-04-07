# N-Queens Problem using Backtracking (prints all solutions)

def print_board(board):
    for row in board:
        print(" ".join("Q" if cell else "." for cell in row))
    print()


def is_safe(board, row, col, N):
    # check row on left
    for j in range(col):
        if board[row][j]:
            return False

    # check upper diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # check lower diagonal
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j]:
            return False

    return True


def solve(board, col, N, solutions):
    if col == N:
        # found one solution
        solutions.append([row[:] for row in board])
        return

    for row in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = 1
            solve(board, col + 1, N, solutions)
            board[row][col] = 0  # backtrack


def n_queens(N):
    board = [[0] * N for _ in range(N)]
    solutions = []
    solve(board, 0, N, solutions)

    if not solutions:
        print("No solution exists.")
    else:
        print(f"Total solutions for {N}-Queens: {len(solutions)}\n")
        for sol in solutions:
            print_board(sol)


# Driver
if __name__ == "__main__":
    n = int(input("Enter value of N: "))
    n_queens(n)
