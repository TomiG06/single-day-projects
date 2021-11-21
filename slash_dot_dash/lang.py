alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N","O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "] 

chars = ["/", "-", "."]
lang = [x+y+z for x in chars for y in chars for z in chars]

toCode = dict(zip(alphabet, lang))
toEng = dict(zip(lang, alphabet))