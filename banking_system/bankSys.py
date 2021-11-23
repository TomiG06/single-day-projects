import sys

pin = "1234"

def read():
    with open("balance.txt", "r") as f:
        return float(f.read())

def write(amount):
    b = read()
    with open("balance.txt", "w") as f:
        f.write(str(b + amount))

def deposit(amount):
    write(amount)

def withdraw(amount):
    if amount <= read():
        write(-amount)
        return True
    return False

for x in range(3):
    if input("Enter pin: ") == pin:
        print("Welcome, user.")
        break
    else:
        if x<2: print("Wrong")
        else:
            print("Try again later")
            sys.exit()

print("""
1.Check Balance
2.Deposit
3.Withdraw
4.Return Card
""")

while True:
    user = int(input(">> "))
    if user == 1:
        print("Balance:", read())
    elif user == 2:
        deposit(float(input('Enter amount: ')))
        print("Deposit made successfully")
    elif user == 3:
        print("Withdrawal made successfully") if withdraw(float(input("Enter amount: "))) else print("Be sure that given amount is\nless or equal than you balance")
    elif user == 4:
        break
    else:
        print("Invalid Input")