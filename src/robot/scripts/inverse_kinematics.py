import math
from sympy import *

def compute_IK(Px, Py, Pz):
    
    th2, th3, th4 = symbols('th2 th3 th4') 

    lb1 = 0.025; 
    l1 = 0.110; 
    l2 = 0.38; 
    l3 = 0.38 
    l4 = 0.38
    l5 = 0.04;
    #Px = 0.6;
    #Py = 0.5;
    #Pz = 0.6;


    th1 = atan(Py/Px)

    eq1 = (l2*cos(th2)+l3*cos(asin((-Pz + l1 + lb1 - l2*sin(th2))/(l3))) + l4 + l5)*cos(th1)

    eq1 = Eq(eq1, Px)

    sol = solve(eq1, th2)

    th2 = float(sol[0])

    th3 = float(-th2 + asin((-Pz+l1+lb1-l2*sin(th2))/(l3)))

    th4 = float(-th2 - th3)

    th5 = float(th4 + 3.14159/2)

    return th1, th2, th3, th4, th5