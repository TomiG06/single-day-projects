import sys, random

words = ["hello", "skate", "jazz", "python", "hangman", "car"]
word = random.choice(words)
word_displayer = ["-" for x in range(len(word))]
false_guesses = 0
deployed_letters = []

print("      HANGMAN       ")
print("I am thinking of a word...")

while false_guesses != 5:
    print("".join(word_displayer))
    while True:
        letter = input("Type a letter: ")
        if letter in deployed_letters:
            print("You have already tried:", deployed_letters) 
        else:
            deployed_letters.append(letter)
            break
    if letter in word:
        for x in range(len(word)):
            if letter == word[x]:
                word_displayer[x] = letter
    else:
        print("Letter not in word")
        false_guesses += 1
    if "".join(word_displayer) == word:
        print("You won! Word: " + word)
        sys.exit()

else:
    print("You lost, word:", word)
