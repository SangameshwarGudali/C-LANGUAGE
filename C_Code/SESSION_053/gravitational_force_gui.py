from tkinter import * 

OL = None

def compute_gravitational(): 
    global OL 
    m1 = float(str_m1.get())
    m2 = float(str_m2.get())
    r = float(str_r.get())
    G = 6.67 * (10 ** -11)
    F = (G * m1 * m2 ) / (r * r)
    if OL != None: 
        OL.destroy()
    OP_str = ("Force = %.3f" % F)
    OL = Label(root_window, text=OP_str)
    OL.grid(row=4, column=0, columnspan=2)

def main(): 
    global root_window, L1, L2, L3, B1, str_m1, str_m2, str_r, E1, E2, E3
    root_window = Tk() 

    L1 = Label(root_window, text="Enter mass of object 1:")
    L2 = Label(root_window, text="Enter mass of object 2:")
    L3 = Label(root_window, text="Enter the distance between objects:")
    B1 = Button(root_window, text='Compute!')
    B1.configure(command = compute_gravitational)
    str_m1 = StringVar() 
    str_m2 = StringVar() 
    str_r = StringVar() 
    E1 = Entry(root_window, textvariable=str_m1)
    E2 = Entry(root_window, textvariable=str_m2)
    E3 = Entry(root_window, textvariable=str_r)
    L1.grid(row=0, column=0)
    L2.grid(row=1, column=0)
    L3.grid(row=2, column=0)
    E1.grid(row=0, column=1)
    E2.grid(row=1, column=1)
    E3.grid(row=2, column=1)
    B1.grid(row=3, column=0)
    root_window.mainloop()

main() 