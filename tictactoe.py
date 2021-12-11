from pandas import DataFrame
import numpy as np

class TicTacToe:
    def __init__(self):
        self.table = np.array([[" ", " ", " "]] * 3)
        self.valid = ["a0", "a1", "a2", "b0", "b1", "b2", "c0", "c1", "c2"]
        self.marks = ["X", "O"]

    def deptab(self):
        print(DataFrame(self.table, columns=["a", "b", "c"]))

    def deploy(self, position, m):
        columns = {"a":0, "b":1, "c":2}
        y, x = position
        x = int(x)
        if self.table[x][columns.get(y)] == " ":
            self.table[x][columns.get(y)] = m
            self.valid.remove(y+str(x))
            return True
        return False

    def check(self):
        for x in self.table:
            if all([y == x[0] and y in ['X', 'O'] for y in x]):
                    return "Computer Wins" if x[0] == "O" else "Player Wins"

        c1, c2, c3 = [self.table[x] for x in range(3)]
        for l in range(3):
            if c1[l] == c2[l] == c3[l] and all([self.table[x][l] in self.marks for x in range(3)]):
                return "Computer Wins" if c1[l] == "O" else "Player Wins"
        
        if self.table[0][0] == self.table[1][1] == self.table[2][2] and all(self.table[x][x] in self.marks for x in range(3)):
            return "Computer Wins" if self.table[1][1] == "O" else "Player Wins"

        if self.table[2][0] == self.table[1][1] == self.table[0][2] and all(self.table[abs(x-2)][x] in self.marks for x in range(3)):
            return "Computer Wins" if self.table[1][1] == "O" else "Player Wins"
        
        if all(" " not in self.table[x] for x in range(3)):
            return "Draw"

class Computer:
    def move(self):
        board.deploy(np.random.choice(board.valid), "O")

if __name__ == "__main__":
    import os

    computer = Computer()
    board = TicTacToe()

    while True:
        os.system("clear")
        print('Player: X\nComputer: O')
        board.deptab()
        print(board.valid)

        c = board.check()
        if c != None:
            print(c)
            break
        
        while True:
            try:
                ver = board.deploy(input("Enter position(a0): "), 'X')
                if ver == True:
                    if board.check() == None: computer.move() 
                    else: print(board.check())
                    break
                else:
                    print('That position is already assigned')
            except (ValueError, IndexError, KeyError):
                print("Enter a valid position")