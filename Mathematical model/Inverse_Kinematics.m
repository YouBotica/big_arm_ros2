syms th2 th3

lb1 = 0.025; l1 = 0.110; l2 = 0.38; l3 = 0.38, l4 = 0.38; l5 = 0.04;
th5 = 0;
th4 = 0;
Px = 0.6;
Py = 0.5;
Pz = 0.6;

th1 = atan(Py/Px);

eq1 = (l2*cos(th2)+l3*cos(asin((-Pz + l1 + lb1 - l2*sin(th2))/(l3))) + l4 + l5)*cos(th1) == Px;

%solve(eq1, th2, 'PrincipalValue',true)

th2 = double(vpasolve(eq1, th2, [-3.14159, 3.14159]))


th3 = -th2 + asin((-Pz+l1+lb1-l2*sin(th2))/(l3));

th4 = -th2 - th3

%%
syms th1 th2 th3 th4 th5 
syms lb1 l1 l2 l3 l4 l5
syms Px Py Pz


eq1 = (l2*cos(th2)+l3*cos(asin((-Pz + l1 + lb1 - l2*sin(th2))/(l3))) + l4 + l5)*cos(th1) == Px;

