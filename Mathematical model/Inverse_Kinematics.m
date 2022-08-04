syms th2 th3

lb1 = 0.025; l1 = 0.110; l2 = 0.38; l3 = 0.38, l4 = 0.38; l5 = 0.04;
th5 = 0;
th4 = 0;
Px = -0.6;
Py = -0.5;
Pz = 0.6;

th1 = atan(Py/Px);

eq1 = (l2*cos(th2)+l3*cos(asin((-Pz + l1 + lb1 - l2*sin(th2))/(l3))) + l4 + l5)*cos(th1) == Px;

%solve(eq1, th2, 'PrincipalValue',true)

th2 = double(vpasolve(eq1, th2, [-3.14159, 3.14159]))


th3 = -th2 + asin((-Pz+l1+lb1-l2*sin(th2))/(l3));

th4 = -th2 - th3

%% Upper Elbow:
syms th2 th3

lb1 = 0.025; l1 = 0.110; l2 = 0.38; l3 = 0.38, l4 = 0.38; l5 = 0.04;
th5 = 0;
th4 = 0;
Px = 0.6;
Py = 0.5;
Pz = 0.6;

th1 = atan2(Py, Px);
eq1 = l1 +lb1 - l2*sin(th2) + l3*sin(acos((sqrt(Px^2+Py^2)-l2*cos(th2)-l4-l5)/l3)) == Pz;

th2 = double(vpasolve(eq1, th2, [-3.14159, 3.14159]));

th3 = th2 - acos((sqrt(Px^2+Py^2)-l2*cos(th2)-l4-l5)/(l3));

th4 = -th2 - th3;

