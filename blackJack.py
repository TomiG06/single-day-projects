import random, sys

class Cards_Stack:
    def __init__(self):
        self.cards = [x for x in range(1, 11)]*4 + [10]*12
        random.shuffle(self.cards)
    def give(self):
        #Combination of Peek and Pop stack methods
        card = self.cards[-1]
        self.cards.pop()
        return card

class Player:
    def __init__(self, name, player=True):
        self.cards = 0
        self.plays = True
        self.player = player
        self.name = name
    
    def hit(self, card):
        if card == 1:
            if self.player:
                card = 1 if input("You got an Ace!\nWill you count it as 1 or 11?") == "1" else 11
            else:
                card == 1 if self.cards+11 > 21 else 11
        self.cards += card
        if self.cards >= 21:
            print(f"{self.name}: {self.cards}")
            if self.cards == 21:
                print(f"{self.name} won")
            else:
                print(f"{self.name} got burnt")
            sys.exit()

    def stay(self):
         self.plays = False

def main():
    cards = Cards_Stack()
    player = Player(input("Enter name: "))
    opponent = Player("Bob", False)

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

if __name__ == "__main__":
    main()