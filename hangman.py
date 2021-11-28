import random

words = ["hello", "skate", "jazz", "python", "hangman", "car"]
word = random.choice(words)
word_displayer = ["-"] * len(word)
false_guesses = 0
deployed_letters = []

print("\tHANGMAN")
print("I am thinking of a word...")

while false_guesses != 5:
    print(f"False Guesses: {false_guesses}/5")
    print("".join(word_displayer))
    while True:
        letter = input("Type a letter: ")
        if letter in deployed_letters:
            print("You have already tried:", deployed_letters) 
        else:
            deployed_letters.append(letter)
            break
    if letter in word:
        for i, x in enumerate(word):
            if x == letter:
                word_displayer[i] = x
    else:
        print("Letter not in word")
        false_guesses += 1
    if "".join(word_displayer) == word:
        print("You won! Word: " + word)
        break

else:
    print("You lost, word:", word)
