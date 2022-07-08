%% Lagrange Mathematical Model:

% WARNING: RUN THE FORWARD_KINEMATICS.M CODE FIRST TO LOAD THE REQUIRED WORKSPACE!
syms lb1 l1 l2 l3 l4 l5
syms m1 m2 m3 m4 m5
syms delta % link 4 is tilted by an angle delta
syms l1_Izz l2_Izz l3_Izz l4_Izz l5_Izz 
syms g
syms u1 u2 u3 u4 u5
syms beta1 beta2 beta3 beta4 beta5
syms tau1 tau2 tau3 tau4 tau5 


%% Positions:
% Link 1:
x1 = 0; y1 = 0; z1 = lb1 + l1;

% Link 2:
P_2_2 = [l2/2*cos(th2); l2/2*sin(th2); 0; 1];
P_2_B = vpa(T_1_B*T_2_1*P_2_2, 6);
x2 = P_2_B(1);
y2 = P_2_B(2);
z2 = P_2_B(3);

% Link 3:
P_3_3 = [l3/2*cos(th3); l3/2*sin(th3); 0; 1];
P_3_B = vpa(T_1_B*T_2_1*T_3_2*P_3_3, 6);
x3 = P_3_B(1);
y3 = P_3_B(2);
z3 = P_3_B(3);

% Link 4:
P_4_4 = [l4/2*cos(th4); l4/2*sin(th4); 0; 1];
P_4_B = vpa(T_1_B*T_2_1*T_3_2*T_4_3*P_4_4, 6);
x4 = P_4_B(1);
y4 = P_4_B(2);
z4 = P_4_B(2);

% Link 5:
P_5_5 = [-l5/2*cos(th5); -l5/2*sin(th5); 0; 1];
P_5_B = [T_1_B*T_2_1*T_3_2*T_4_3*T_5_4*P_5_5];
x5 = P_5_B(1);
y5 = P_5_B(2);
z5 = P_5_B(3);

%% Time variables:
syms x1(t) y1(t) z1(t) x2(t) y2(t) z2(t) x3(t) y3(t) z3(t) x4(t) y4(t) z4(t) 
syms x5(t) y5(t) z5(t)
syms th1(t) th2(t) th3(t) th4(t) th5(t)

%% Positions as time equations:

% Link 1:
x1 = 0; y1 = 0; z1 = l1-lb1;

% Link 2:
x2 = 0.5*l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 0.5*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y2 = 0.5*l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + 0.5*l2*cos(0.5*pi)*cos(th1)*sin(th2);
z2 = l1 + lb1 - 0.5*l2*sin(0.5*pi)*sin(th2) - 0.5*l2*cos(0.5*pi)*cos(th2)*sin(pi);

% Link 3:
x3 = 0.5*l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2)) + 0.5*l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1)) + l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y3 = 0.5*l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2)) + 0.5*l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
z3 = l1 + lb1 - 0.5*l3*sin(th3)*(1.0*sin(0.5*pi)*cos(0.5*pi - 1.0*th2) + 1.0*cos(0.5*pi)*sin(pi)*sin(0.5*pi - 1.0*th2)) - 1.0*l2*sin(0.5*pi)*sin(th2) + 0.5*l3*cos(th3)*(1.0*sin(0.5*pi)*sin(0.5*pi - 1.0*th2) - 1.0*cos(0.5*pi)*sin(pi)*cos(0.5*pi - 1.0*th2)) - 1.0*l2*cos(0.5*pi)*cos(th2)*sin(pi);

% Link 4:
x4 = 0.5*l4*sin(th4)*(sin(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2)) + cos(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1))) - 0.5*l4*cos(th4)*(1.0*sin(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1)) - cos(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2))) + l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2)) + l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1)) + l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y4 = 0.5*l4*sin(th4)*(sin(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + cos(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2)) + 0.5*l4*cos(th4)*(cos(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) - 1.0*sin(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
z4 = 0.5*l4*sin(th4)*(sin(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + cos(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2)) + 0.5*l4*cos(th4)*(cos(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) - 1.0*sin(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);

% Link 5:
x5 = l4*sin(th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1))) + l3*cos(th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) + l3*sin(th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) - (l5*cos(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1))) + sin(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)))))/2 - (l5*sin(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1))) - sin(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)))))/2 + l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + l4*cos(th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1))) - 1.0*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y5 = l3*cos(th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) + l3*sin(th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) - (l5*cos(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1))) + sin(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)))))/2 - (l5*sin(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1))) - sin(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)))))/2 + l4*cos(th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1))) + l4*sin(th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1))) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
z5 = l1 + lb1 - l3*sin(th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - (l5*cos(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) + sin(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi))) - sin(pi - th4)*(cos(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - sin(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)))))/2 - 1.0*l2*sin(0.5*pi)*sin(th2) + (l5*sin(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - sin(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi))) + sin(pi - th4)*(cos(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) + sin(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)))))/2 + l4*cos(th4)*(cos(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) + sin(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi))) - l4*sin(th4)*(cos(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - sin(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi))) + l3*cos(th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) - 1.0*l2*cos(0.5*pi)*cos(th2)*sin(pi);

%% Linear velocities:
x1d = diff(x1, t);
y1d = diff(y1, t);
z1d = diff(z1, t);

x2d = diff(x2, t);
y2d = diff(y2, t);
z2d = diff(z2, t);

x3d = diff(x3, t);
y3d = diff(y3, t);
z3d = diff(z3, t);

x4d = diff(x4, t);
y4d = diff(y4, t);
z4d = diff(z4, t);

x5d = diff(x5, t);
y5d = diff(y5, t);
z5d = diff(z5, t);

%% Angular velocities:
th1d = diff(th1,t);
th2d = diff(th2,t);
th3d = diff(th3,t);
th4d = diff(th4,t);
th5d = diff(th5,t);

%% Kinetic Energy:

T1 = 0.5*m1*(x1d^2+y1d^2+z1d^2) + 0.5*l1_Izz*th1d^2;
T2 = 0.5*m2*(x2d^2+y2d^2+z2d^2) + 0.5*l2_Izz*(th1d^2+th2d^2);
T3 = 0.5*m3*(x3d^2+y3d^2+z3d^2) + 0.5*l3_Izz*(th1d^2+th2d^2+th3d^2);
T4 = 0.5*m4*(x4d^2+y4d^2+z4d^2) + 0.5*l4_Izz*(th1d^2+th2d^2+th3d^2+th4d^2);
T5 = 0.5*m5*(x5d^2+y5d^2+z5d^2) + 0.5*l5_Izz*(th1d^2+th2d^2+th3d^2+th4d^2+th5d^2);

T = T1 + T2 + T3 + T4 + T5;

%% Potential energy:

V1 = th1*0;
V2 = m2*g*z2;
V3 = m3*g*z3;
V4 = m4*g*z4;
V5 = m5*g*z5;

V = V1 + V2 + V3 + V4 + V5;

%% Lagrangian:

L = T - V;

%% Euler-Lagrange Equation:

%th1:
eq1 = diff(diff(L,th1d),t) - diff(L,th1) + beta1*th1d - tau1 == 0;

%eq1 = simplify(eq1);
%th2:
eq2 = diff(diff(L,th2d),t) - diff(L,th2) + beta2*th2d - tau2 == 0;
%eq2 = simplify(eq2);
%th3:
eq3 = diff(diff(L,th3d),t) - diff(L,th3) + beta3*th3d - tau3 == 0;
%eq3 = simplify(eq3);
%th4:
eq4 = diff(diff(L,th4d),t) - diff(L,th4) + beta4*th4d - tau4 == 0;
%eq4 = simplify(eq4);
%th5:
eq5 = diff(diff(L,th5d),t) - diff(L,th5) + beta5*th5d - tau5 == 0;
%eq5 = simplify(eq5);





%% Only don't run this with the other code:

diary mov_q1
th1dd = isolate(eq1, diff(th1(t), t, t))
diary off

diary mov_q2
th2dd = isolate(eq2, diff(th2(t), t, t))
diary off

diary mov_q3
th3dd = isolate(eq3, diff(th3(t), t, t))
diary off

diary mov_q4
th4dd = isolate(eq4, diff(th4(t), t, t))
diary off

diary mov_q5
th5dd = isolate(eq5, diff(th5(t), t, t))
diary off