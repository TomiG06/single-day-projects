import random, sys

class Cards_Stack:
    def __init__(self):
        self.cards = [x for _ in range(4) for x in range(1, 11)]
        for _ in range(12):
            self.cards.append(10)
        random.shuffle(self.cards)
        self.TOP = len(self.cards)
    
    def peek(self):
        return self.cards[self.TOP - 1]

    def pop(self):
        self.cards.pop()
        self.TOP -= 1

cards = Cards_Stack()

class Player:
    def __init__(self, name):
        self.cards = 0
        self.plays = True
        self.name = name
    
    def hit(self, card):
        self.cards += card
        if self.cards == 21:
            print(f"{self.name} won")
            sys.exit()

    def stay(self):
         self.plays = False

player = Player(input("Enter name: "))
opponent = Player("Bob")

while player.cards < 21 and opponent.cards < 21 and player.plays:
    print(f"{player.name}: {player.cards}\nOpponent: {opponent.cards}")
    if input("Hit or Stay(H, S)? ").upper() == "H":
        player.hit(cards.peek())
        cards.pop()
    else:
        player.stay()
    opponent.hit(cards.peek())
    cards.pop()
    if not player.plays:
        while opponent.cards < 22:
            opponent.hit(cards.peek())
            cards.pop()

if player.cards > 21 and opponent.cards < 22: print("You are burnt")
if opponent.cards > 21 and player.cards < 22: print(f"Oppenent is burnt\n{player.name} wins")
if opponent.cards > 21 and player.cards > 21: print(f"{player.name} and {opponent.name} are both burnt\nDRAW")