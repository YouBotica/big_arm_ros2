syms th1 th2 th3 th4 th5
syms l1 l1b l2 l3 l4 l5
syms Px Py Pz

left = asin((Pz-l1-l1b-l2*sin(th2)-l3*cos(th3)*sin(th2))/(-l4*cos(th3)*sin(th2)-l5*sin(th5)*cos(th3)*sin(th2)));
right = acos(((Py/sin(th1))-l2*cos(th2)-l3*sin(th3)*cos(th2))/(l4*sin(th3)*cos(th2)+l5*cos(th5)*sin(th3)*cos(th2)));

eq1 = left - right == 0;
isolate(eq1, th2)

%%


fun = @get_coords;
x0 = [0,0,0];
x = fsolve(fun,x0)

function F = get_coords(x)
    th5 = 0
    th1 = 0
    l1 = 0.1
    l2 = 0.1
    l1b = 0.1
    l3 = 0.1
    l4 = 0.1
    l5 = 0.06
    Px = 0.1
    Py = 0.1 
    Pz = 0.1

    F(1) = -Px + (l2*cos(th2) + l3*sin(th3)*cos(th2) + l4*cos(th4)*sin(th3)*cos(th2) + l5*cos(th5)*cos(th4)*sin(th3)*cos(th2))*(-cos(th1))
    F(2) = -Py + (l2*cos(th2) + l3*sin(th3)*cos(th2) + l4*cos(th4)*sin(th3)*cos(th2) + l5*cos(th5)*cos(th4)*sin(th3)*cos(th2))*(-sin(th1))
    F(3) = -Pz + l1 + l1b + l2*sin(th2) + l3*cos(th3)*sin(th2) - l4*sin(th4)*cos(th3)*sin(th2) - l5*sin(th5)*sin(th4)*cos(th3)*sin(th2)
    
    x0 = [0, 0, 0]
    
    solve([eq1, eq2, eq3], [th2, th3, th4])

end