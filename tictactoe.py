from pandas import DataFrame
import numpy as np
import os

table = np.array([[" ", " ", " "]] * 3)

valid = ["a0", "a1", "a2", "b0", "b1", "b2", "c0", "c1", "c2"]

marks = ["X", "O"]

def deptab():
    print(DataFrame(table, columns=["a", "b", "c"]))

def deploy(x, y, m):
    global table, valid
    columns = {"a":0, "b":1, "c":2}
    if table[x][columns.get(y)] == " ":
        table[x][columns.get(y)] = m
        valid.remove(y+str(x))
        return True
    return False

def check():
    for x in table:
        if all([y == x[0] and y in ['X', 'O'] for y in x]):
                return "Computer Wins" if x[0] == "O" else "Player Wins"

    c1, c2, c3 = [table[x] for x in range(3)]
    for l in range(3):
        if c1[l] == c2[l] == c3[l] and all([table[x][l] in marks for x in range(3)]):
            return "Computer Wins" if c1[l] == "O" else "Player Wins"
    
    if table[0][0] == table[1][1] == table[2][2] and all(table[x][x] in marks for x in range(3)):
        return "Computer Wins" if table[1][1] == "O" else "Player Wins"

    if table[2][0] == table[1][1] == table[0][2] and all(table[abs(x-2)][x] in marks for x in range(3)):
        return "Computer Wins" if table[1][1] == "O" else "Player Wins"
    
    if all(" " not in table[x] for x in range(3)):
        return "Draw"

def com():
    p = np.random.choice(valid)
    deploy(int(p[1]), p[0], "O")

while True:
    os.system("clear")
    print('Player: X\nComputer: O')
    deptab()
    print(valid)
    print()
    c = check()
    if c != None:
        print(c)
        break
    while True:
        p = input("Enter position(a0): ")
        try:
            ver = deploy(int(p[1]), p[0], 'X')
            if ver == True:
                com() if check() == None else print(check())
                break
            else:
                print('That position is already assigned')
        except (ValueError, IndexError, KeyError):
            print("Enter a valid position")