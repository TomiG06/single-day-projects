from coders import encoder, decoder

while True:
    try:
        user = input(">> ")
        if user == "encode":
            print(encoder(input("Text: ")))
        elif user == "decode":
            print(decoder(input("Text: ")))
        elif user == "terminate":
            break
        else:
            print("Invalid Input\nCommands: 'encode', 'decode', 'terminate'")
    except (KeyError, TypeError):
        print("Invalid Key")