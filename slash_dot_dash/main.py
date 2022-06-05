from coders import encoder, decoder
from sys import argv

try:
    if argv[1] == "-e":
        print(encoder(argv[2]))
    elif argv[1] == "-d":
        print(decoder(argv[2]))
except (KeyError, TypeError):
    print("Invalid Key")
