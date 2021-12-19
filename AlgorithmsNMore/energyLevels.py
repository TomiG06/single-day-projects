#Algorithm to distribute electrons of an atom in energy levels
#Find more about energy levels: https://en.wikipedia.org/wiki/Energy_level
#Able to distribute up to 54 electrons

#Defining a class for levels
class Level:
    def __init__(self, n):
        self.n = n
        self.max = 2*n**2 if n < 5 else 32

#We' ll be using 7 levels
Kl = Level(1)
Ll = Level(2)
Ml = Level(3)
Nl = Level(4)
Ol = Level(5)
Pl = Level(6)
Ql = Level(7)

#Defining an array of Levels
levels = [Kl, Ll, Ml, Nl, Ol, Pl, Ql]


#Distributing electrons
def distribute(e):
    distr = []
    for l in levels:
        if 9 <= e <= 26 and l.max > 8:
            while (e - 18 > 0 or e - 8 > 0) and e >= 8 :
                distr.append(18) if e - 18 > 0 else distr.append(8)
                e -= distr[-1]
            distr.append(e)
            e = 0
        if e <= 0: break
        if e - l.max > 0:
            d = l.max
        else:
            d = e
        e -= d

        distr.append(d)
    
    #Some other characteristics of the element
    group = len(distr) 
    period = distr[-1]
    return distr, group, period
