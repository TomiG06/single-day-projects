import random, sys

class Cards_Stack:
    def __init__(self):
        self.cards = [x for x in range(1, 11)]*4 + [10]*12
        random.shuffle(self.cards)
        self.TOP = len(self.cards)-1
    def give(self):
        #Combination of Peek and Pop stack methods
        card = self.cards[self.TOP]
        self.cards.pop()
        self.TOP -= 1
        return card

cards = Cards_Stack()

class Player:
    def __init__(self, name):
        self.cards = 0
        self.plays = True
        self.name = name
    
    def hit(self, card):
        self.cards += card
        if self.cards >= 21:
            print(f"{player.name}: {player.cards}\nOpponent: {opponent.cards}")
            if self.cards == 21:
                print(f"{self.name} won")
            else:
                print(f"{player.name} got burnt\nBob won!") if self == player else print(f"Bob got burnt\n{player.name} won")
            sys.exit()

    def stay(self):
         self.plays = False

player = Player(input("Enter name: "))
opponent = Player("Bob")

while player.cards < 21 and opponent.cards < 21 and player.plays:
    print(f"{player.name}: {player.cards}\nOpponent: {opponent.cards}")
    if input("Hit or Stay(H, S)? ").upper() == "H":
        player.hit(cards.give())

    else:
        player.stay()
    opponent.hit(cards.give())
    if not player.plays:
        while True:
            opponent.hit(cards.give())