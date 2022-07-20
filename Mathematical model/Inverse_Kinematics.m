syms th2 th3

lb1 = 0.025; l1 = 0.110; l2 = 0.38; l3 = 0.38, l4 = 0.38; l5 = 0.04;
th5 = 0;
th4 = 0;
Px = 0.6;
Py = 0.6;
Pz = 0.6;

th1 = atan(Py/Px);

eq1 = (l2*cos(th2)+l3*cos(asin((-Pz + l1 + lb1 - l2*sin(th2))/(l3))) + l4 + l5)*cos(th1) == Px;

%solve(eq1, th2, 'PrincipalValue',true)

th2 = double(vpasolve(eq1, th2, [-3.14159, 3.14159]))


th3 = -th2 + asin((-Pz+l1+lb1-l2*sin(th2))/(l3));

th4 = -th2 - th3

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