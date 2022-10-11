import sys 

def main(): 
    
    m1 = float(input("Enter mass of object 1:"))
    m2 = float(input("Enter mass of object 2:"))
    r = float(input("Enter the distane between objects:"))
    G = 6.67 * (10 ** -11)
    F = (G * m1 * m2) / (r * r) 
    print("Force = %.3f" % F)

main()