import math
from sympy import *


'''
Constraints:
1. z > 0.1 m
2. th2 <= 0 and th2 >= -3.14159
3. th3 >= -2.6 and <= 2.6
4. th4 >= -2.6 and <= 2.6
5. th5 >= -2.6 and <= 2.6
6. sqrt(x^2 + y^2 + z^2) < 1.12 and >= 0.1
'''


def compute_IK(Px, Py, Pz):
    
    th2, th3, th4 = symbols('th2 th3 th4') 

    lb1 = 0.025; 
    l1 = 0.110; 
    l2 = 0.38; 
    l3 = 0.38 
    l4 = 0.38
    l5 = 0.04;


    th1 = atan2(Py, Px)

    eq1 = (l2*cos(th2)+l3*cos(asin((-Pz + l1 + lb1 - l2*sin(th2))/(l3))) + l4 + l5)*cos(th1)

    eq1 = Eq(eq1, Px)

    sol = solve(eq1, th2)

    if (len(sol) <= 0): # If eq1's configuration is not possible, try with this one:
        eq2 = l1 + lb1 - l2*sin(th2) + l3*sin(acos((math.sqrt(Px**2+Py**2)-l2*cos(th2)-l4-l5)/l3))
        eq2 = Eq(eq2, Pz)
        sol = solve(eq2, th2)

        if (len(sol) == 0): # No solution found
            return -100, -100, -100, -100, -100
        
        # If a solution was found, compute the other angles
        th2 = float(sol[0])
        th3 = th2 - acos((math.sqrt(Px**2+Py**2)-l2*cos(th2)-l4-l5)/(l3))
        th4 = -th2 - th3

        th5 = 3.14159/2 

        if (Pz < 0.1):
            return -101, -101, -101, -101, -101
        elif (th2 >= 0.0 or th2 <= -3.14159):
            return -102, -102, -102, -102, -102
        elif (abs(th3) >= 2.6):
            return -103, -103, -103, -103, -103
        elif (abs(th4) >= 2.6):
            return -104, -104, -104, -104, -104
        elif (abs(th5) >= 2.6):
            return -105, -105, -105, -105, -105      
        elif (math.sqrt(Px**2 + Py**2 + Pz**2) >= 1.12 ):
            return -106, -106, -106, -106, -106
        else: # All constraints OK :)
            return th1, th2, th3, th4, th5
        

    th2 = float(sol[0])

    th3 = float(-th2 + asin((-Pz+l1+lb1-l2*sin(th2))/(l3)))

    th4 = float(-th2 - th3)

    th5 = float(th4 + 3.14159/2)

    return th1, th2, th3, th4, th5