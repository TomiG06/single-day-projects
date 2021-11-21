from lang import toCode, toEng

def encoder(txt):
    return "".join([toCode.get(x.upper()) for x in txt])

def decoder(txt):
    return "".join([toEng.get(txt[x:x+3]) for x in range(0, len(txt), 3)]) if len(txt)%3==0 else "Invalid Text"
