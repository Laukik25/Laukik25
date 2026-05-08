N = 8

board = [[0 for x in range(N)] for y in range(N)]

def isSafe(board, row, col):

    for i in range(col):
        if board[row][i] == 1:
            return False

    i = row
    j = col

    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    i = row
    j = col

    while j >= 0 and i < N:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    return True

def solveNQUtil(board, col):

    if col >= N:
        return True

    for i in range(N):

        if isSafe(board, i, col):

            board[i][col] = 1

            if solveNQUtil(board, col + 1):
                return True

            board[i][col] = 0

    return False

def solveNQ():

    if not solveNQUtil(board, 0):
        print("Solution does not exist")
        return False

    for i in board:
        print(i)

solveNQ()