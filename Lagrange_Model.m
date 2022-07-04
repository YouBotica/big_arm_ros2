%% Lagrange Mathematical Model:
syms x1(t) y1(t) z1(t) x2(t) y2(t) z2(t) x3(t) y3(t) z3(t) x4(t) y4(t) z4(t) 
syms x5(t) y5(t) z5(t)
syms l1 l2 l3 l4 l5
syms m1 m2 m3 m4 m5
syms th1(t) th2(t) th3(t) th4(t) th5(t)
syms delta % link 4 is tilted by an angle delta
syms l1_Izz l2_Izz l3_Izz l4_Izz l5_Izz 
syms g
syms u1 u2 u3 u4 u5
syms beta1 beta2 beta3 beta4 beta5
syms tau1 tau2 tau3 tau4 tau5 



%% Angular velocities:
th1d = diff(th1,t);
th2d = diff(th2,t);
th3d = diff(th3,t);
th4d = diff(th4,t);
th5d = diff(th5,t);

%% Positions and velocities:
% Link 1:
%x1 = 0; y1 = 0; z1=l1;
x1d = diff(x1, t); y1d = diff(y1,t); z1d = diff(z1,t);

% Link 2:
x2 = -0.5*l2*cos(th2)*cos(th1);
y2 = -0.5*l2*cos(th2)*sin(th1);
z2 = l1 - 0.5*l2*sin(th2);

x2d = diff(x2,t);
y2d = diff(y2,t);
z2d = diff(z2,t);

% Link 3:
x3 = 2*x2 - 0.5*l3*sin(th3)*cos(th2)*cos(th1);
y3 = 2*y2 - 0.5*l3*sin(th3)*cos(th2)*sin(th1);
z3 = l1 - 2*l2*sin(th2) + 0.5*l3*cos(th3)*cos(th2);
%z3 = l1 - 2*l2*sin(th2) + 0.5*l3*cos(th3+th2);

x3d = diff(x3,t);
y3d = diff(y3,t);
z3d = diff(z3,t);

% Link 4:
x4 = x3 + 0.5*l4*cos(-delta+th4)*sin(th3)*cos(th2)*cos(th1) - 0.5*l3*sin(th3)*cos(th2)*cos(th1);
y4 = y3 - 0.5*l3*sin(th3)*cos(th2)*sin(th1) - 0.5*l4*cos(-delta+th4)*sin(th3)*cos(th2)*cos(th1);
%z4 = z3 + 0.5*l3*cos(th3)*cos(th2) + 0.5*l4*sin(-delta+th4)*cos(th3+th2);
z4 = z3 + 0.5*l3*cos(th3)*cos(th2) + 0.5*l4*sin(-delta+th4)*cos(th3)*cos(th2); % Last is cos or sin?

x4d = diff(x4,t);
y4d = diff(y4,t);
z4d = diff(z4,t);

% Link 5:
x5 = x4 + 0.5*l4*cos(-delta+th4)*sin(th3)*cos(th2)*cos(th1) + 0.5*l5*cos(th5)*cos(-delta+th4)*sin(th3)*cos(th2)*cos(th1);
y5 = y4 - 0.5*l4*cos(-delta+th4)*sin(th3)*cos(th2)*sin(th1) - 0.5*l5*cos(th5)*cos(-delta+th4)*sin(th3)*cos(th2)*sin(th1);
z5 = z4 + 0.5*l4*sin(-delta+th4)*cos(th3)*cos(th2) + 0.5*l5*sin(th5)*sin(-delta+th4)*cos(th3)*cos(th2);

x5d = diff(x5,t);
y5d = diff(y5,t);
z5d = diff(z5,t);

%% Kinetic Energy:

T1 = 0.5*m1*(x1d^2+y1d^2+z1d^2) + 0.5*l1_Izz*th1d^2;
T2 = 0.5*m2*(x2d^2+y2d^2+z2d^2) + 0.5*l2_Izz*(th1d^2+th2d^2);
T3 = 0.5*m3*(x3d^2+y3d^2+z3d^2) + 0.5*l3_Izz*(th1d^2+th2d^2+th3d^2);
T4 = 0.5*m4*(x4d^2+y4d^2+z4d^2) + 0.5*l4_Izz*(th1d^2+th2d^2+th3d^2+th4d^2);
T5 = 0.5*m5*(x5d^2+y5d^2+z5d^2) + 0.5*l5_Izz*(th1d^2+th2d^2+th3d^2+th4d^2+th5d^2);

T = T1 + T2 + T3 + T4 + T5;

%% Potential energy:

V1 = th1*0;
V2 = m2*g*0.5*l2*sin(th2);
V3 = m3*g*(l2*sin(th2)+0.5*l3*cos(th3)*cos(th2));
V4 = m4*g*(l2*sin(th2)+l3*cos(th3)*cos(th2)+0.5*l4*sin(-delta+th4)*cos(th3)*cos(th2));
V5 = m5*g*(l2*sin(th2)+l3*cos(th3)*cos(th2)+l4*sin(-delta+th4)*cos(th3)*cos(th2)+0.5*l5*sin(-delta+th4)*cos(th3)*cos(th2));

V = V1 + V2 + V3 + V4 + V5;

%% Lagrangian:
syms x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4 
syms x5 y5 z5
syms l1 l2 l3 l4 l5
syms m1 m2 m3 m4 m5
syms th1 th2 th3 th4 th5
syms delta % link 4 is tilted by an angle delta
syms l1_Izz l2_Izz l3_Izz l4_Izz l5_Izz 
syms g
syms u1 u2 u3 u4 u5
syms beta1 beta2 beta3 beta4 beta5
syms tau1 tau2 tau3 tau4 tau5 



L = T - V;
L = (m5*((l2*cos(th1)*cos(th2)*th1d - l2*sin(th1)*sin(th2)*th2d + l3*cos(th1)*cos(th2)*sin(th3)*th1d + l3*cos(th2)*cos(th3)*sin(th1)*th3d - l3*sin(th1)*sin(th2)*sin(th3)*th2d - (l4*sin(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th2)*sin(th1)*sin(th3)*sin(delta - th4)*th4d)/2 + (l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*cos(delta - th4)*th1d)/2 + (l4*cos(th2)*cos(th3)*sin(th1)*cos(delta - th4)*th3d)/2 - (l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d)/2 + (l5*cos(th1)*cos(th2)*cos(th5)*sin(th3)*cos(delta - th4)*th1d)/2 + (l5*cos(th2)*cos(th3)*cos(th5)*sin(th1)*cos(delta - th4)*th3d)/2 - (l5*cos(th5)*sin(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l5*cos(th2)*cos(th5)*sin(th1)*sin(th3)*sin(delta - th4)*th4d)/2 - (l5*cos(th2)*sin(th1)*sin(th3)*sin(th5)*cos(delta - th4)*th5d)/2)^2 + (l2*cos(th2)*sin(th1)*th1d + l2*cos(th1)*sin(th2)*th2d - l3*cos(th1)*cos(th2)*cos(th3)*th3d + l3*cos(th2)*sin(th1)*sin(th3)*th1d + l3*cos(th1)*sin(th2)*sin(th3)*th2d + l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d - l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d - l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d + l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d + (l5*cos(th1)*cos(th2)*cos(th3)*cos(th5)*cos(delta - th4)*th3d)/2 - (l5*cos(th2)*cos(th5)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l5*cos(th1)*cos(th5)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l5*cos(th1)*cos(th2)*cos(th5)*sin(th3)*sin(delta - th4)*th4d)/2 - (l5*cos(th1)*cos(th2)*sin(th3)*sin(th5)*cos(delta - th4)*th5d)/2)^2 + (l4*cos(th2)*cos(th3)*cos(delta - th4)*th4d - l3*cos(th3)*sin(th2)*th2d - l3*cos(th2)*sin(th3)*th3d - 2*l2*cos(th2)*th2d + l4*cos(th3)*sin(th2)*sin(delta - th4)*th2d + l4*cos(th2)*sin(th3)*sin(delta - th4)*th3d + (l5*cos(th3)*sin(th2)*sin(th5)*sin(delta - th4)*th2d)/2 + (l5*cos(th2)*sin(th3)*sin(th5)*sin(delta - th4)*th3d)/2 + (l5*cos(th2)*cos(th3)*sin(th5)*cos(delta - th4)*th4d)/2 - (l5*cos(th2)*cos(th3)*cos(th5)*sin(delta - th4)*th5d)/2)^2))/2 + (m4*((l2*cos(th2)*sin(th1)*th1d + l2*cos(th1)*sin(th2)*th2d - l3*cos(th1)*cos(th2)*cos(th3)*th3d + l3*cos(th2)*sin(th1)*sin(th3)*th1d + l3*cos(th1)*sin(th2)*sin(th3)*th2d + (l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d)/2 - (l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d)/2)^2 + (l2*cos(th1)*cos(th2)*th1d - l2*sin(th1)*sin(th2)*th2d + l3*cos(th1)*cos(th2)*sin(th3)*th1d + l3*cos(th2)*cos(th3)*sin(th1)*th3d - l3*sin(th1)*sin(th2)*sin(th3)*th2d + (l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d)/2 - (l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d)/2)^2 + (2*l2*cos(th2)*th2d + l3*cos(th3)*sin(th2)*th2d + l3*cos(th2)*sin(th3)*th3d - (l4*cos(th2)*cos(th3)*cos(delta - th4)*th4d)/2 - (l4*cos(th3)*sin(th2)*sin(delta - th4)*th2d)/2 - (l4*cos(th2)*sin(th3)*sin(delta - th4)*th3d)/2)^2))/2 + (l2_Izz*(th1d^2 + th2d^2))/2 + (m2*(((l2*cos(th1)*cos(th2)*th1d)/2 - (l2*sin(th1)*sin(th2)*th2d)/2)^2 + ((l2*cos(th2)*sin(th1)*th1d)/2 + (l2*cos(th1)*sin(th2)*th2d)/2)^2 + (l2^2*cos(th2)^2*th2d^2)/4))/2 + (l3_Izz*(th1d^2 + th2d^2 + th3d^2))/2 + (m3*((l2*cos(th2)*sin(th1)*th1d + l2*cos(th1)*sin(th2)*th2d - (l3*cos(th1)*cos(th2)*cos(th3)*th3d)/2 + (l3*cos(th2)*sin(th1)*sin(th3)*th1d)/2 + (l3*cos(th1)*sin(th2)*sin(th3)*th2d)/2)^2 + (l2*cos(th1)*cos(th2)*th1d - l2*sin(th1)*sin(th2)*th2d + (l3*cos(th1)*cos(th2)*sin(th3)*th1d)/2 + (l3*cos(th2)*cos(th3)*sin(th1)*th3d)/2 - (l3*sin(th1)*sin(th2)*sin(th3)*th2d)/2)^2 + (2*l2*cos(th2)*th2d + (l3*cos(th3)*sin(th2)*th2d)/2 + (l3*cos(th2)*sin(th3)*th3d)/2)^2))/2 + (l4_Izz*(th1d^2 + th2d^2 + th3d^2 + th4d^2))/2 + (l5_Izz*(th1d^2 + th2d^2 + th3d^2 + th4d^2 + th5d^2))/2 + (l1_Izz*th1d^2)/2 - g*m3*(l2*sin(th2) + (l3*cos(th2)*cos(th3))/2) - g*m5*(l2*sin(th2) + l3*cos(th2)*cos(th3) - l4*cos(th2)*cos(th3)*sin(delta - th4) - (l5*cos(th2)*cos(th3)*sin(delta - th4))/2) - g*m4*(l2*sin(th2) + l3*cos(th2)*cos(th3) - (l4*cos(th2)*cos(th3)*sin(delta - th4))/2) - (g*l2*m2*sin(th2))/2;

%L = (m5*((l2*cos(th1)*cos(th2)*th1d - l2*sin(th1)*sin(th2)*th2d + l3*cos(th1)*cos(th2)*sin(th3)*th1d + l3*cos(th2)*cos(th3)*sin(th1)*th3d - l3*sin(th1)*sin(th2)*sin(th3)*th2d - (l4*sin(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th2)*sin(th1)*sin(th3)*sin(delta - th4)*th4d)/2 + (l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*cos(delta - th4)*th1d)/2 + (l4*cos(th2)*cos(th3)*sin(th1)*cos(delta - th4)*th3d)/2 - (l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d)/2 + (l5*cos(th1)*cos(th2)*cos(th5)*sin(th3)*cos(delta - th4)*th1d)/2 + (l5*cos(th2)*cos(th3)*cos(th5)*sin(th1)*cos(delta - th4)*th3d)/2 - (l5*cos(th5)*sin(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l5*cos(th2)*cos(th5)*sin(th1)*sin(th3)*sin(delta - th4)*th4d)/2 - (l5*cos(th2)*sin(th1)*sin(th3)*sin(th5)*cos(delta - th4)*th5d)/2)^2 + (l2*cos(th2)*sin(th1)*th1d + l2*cos(th1)*sin(th2)*th2d - l3*cos(th1)*cos(th2)*cos(th3)*th3d + l3*cos(th2)*sin(th1)*sin(th3)*th1d + l3*cos(th1)*sin(th2)*sin(th3)*th2d + l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d - l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d - l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d + l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d + (l5*cos(th1)*cos(th2)*cos(th3)*cos(th5)*cos(delta - th4)*th3d)/2 - (l5*cos(th2)*cos(th5)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l5*cos(th1)*cos(th5)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l5*cos(th1)*cos(th2)*cos(th5)*sin(th3)*sin(delta - th4)*th4d)/2 - (l5*cos(th1)*cos(th2)*sin(th3)*sin(th5)*cos(delta - th4)*th5d)/2)^2 + (l4*cos(th2)*cos(th3)*cos(delta - th4)*th4d - l3*cos(th3)*sin(th2)*th2d - l3*cos(th2)*sin(th3)*th3d - 2*l2*cos(th2)*th2d + l4*cos(th3)*sin(th2)*sin(delta - th4)*th2d + l4*cos(th2)*sin(th3)*sin(delta - th4)*th3d + (l5*cos(th3)*sin(th2)*sin(th5)*sin(delta - th4)*th2d)/2 + (l5*cos(th2)*sin(th3)*sin(th5)*sin(delta - th4)*th3d)/2 + (l5*cos(th2)*cos(th3)*sin(th5)*cos(delta - th4)*th4d)/2 - (l5*cos(th2)*cos(th3)*cos(th5)*sin(delta - th4)*th5d)/2)^2))/2 + (m4*((l2*cos(th2)*sin(th1)*th1d + l2*cos(th1)*sin(th2)*th2d - l3*cos(th1)*cos(th2)*cos(th3)*th3d + l3*cos(th2)*sin(th1)*sin(th3)*th1d + l3*cos(th1)*sin(th2)*sin(th3)*th2d + (l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d)/2 - (l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d)/2)^2 + (l2*cos(th1)*cos(th2)*th1d - l2*sin(th1)*sin(th2)*th2d + l3*cos(th1)*cos(th2)*sin(th3)*th1d + l3*cos(th2)*cos(th3)*sin(th1)*th3d - l3*sin(th1)*sin(th2)*sin(th3)*th2d + (l4*cos(th1)*cos(th2)*cos(th3)*cos(delta - th4)*th3d)/2 - (l4*cos(th2)*sin(th1)*sin(th3)*cos(delta - th4)*th1d)/2 - (l4*cos(th1)*sin(th2)*sin(th3)*cos(delta - th4)*th2d)/2 + (l4*cos(th1)*cos(th2)*sin(th3)*sin(delta - th4)*th4d)/2)^2 + (2*l2*cos(th2)*th2d + l3*cos(th3)*sin(th2)*th2d + l3*cos(th2)*sin(th3)*th3d - (l4*cos(th2)*cos(th3)*cos(delta - th4)*th4d)/2 - (l4*cos(th3)*sin(th2)*sin(delta - th4)*th2d)/2 - (l4*cos(th2)*sin(th3)*sin(delta - th4)*th3d)/2)^2))/2 + (l2_Izz*(th1d^2 + th2d^2))/2 + (m2*(((l2*cos(th1)*cos(th2)*th1d)/2 - (l2*sin(th1)*sin(th2)*th2d)/2)^2 + ((l2*cos(th2)*sin(th1)*th1d)/2 + (l2*cos(th1)*sin(th2)*th2d)/2)^2 + (l2^2*cos(th2)^2*th2d^2)/4))/2 + (l3_Izz*(th1d^2 + th2d^2 + th3d^2))/2 + (m1*(0^2 + 0^2 + 0^2))/2 + (m3*((l2*cos(th2)*sin(th1)*th1d + l2*cos(th1)*sin(th2)*th2d - (l3*cos(th1)*cos(th2)*cos(th3)*th3d)/2 + (l3*cos(th2)*sin(th1)*sin(th3)*th1d)/2 + (l3*cos(th1)*sin(th2)*sin(th3)*th2d)/2)^2 + (l2*cos(th1)*cos(th2)*th1d - l2*sin(th1)*sin(th2)*th2d + (l3*cos(th1)*cos(th2)*sin(th3)*th1d)/2 + (l3*cos(th2)*cos(th3)*sin(th1)*th3d)/2 - (l3*sin(th1)*sin(th2)*sin(th3)*th2d)/2)^2 + (2*l2*cos(th2)*th2d + (l3*cos(th3)*sin(th2)*th2d)/2 + (l3*cos(th2)*sin(th3)*th3d)/2)^2))/2 + (l4_Izz*(th1d^2 + th2d^2 + th3d^2 + th4d^2))/2 + (l5_Izz*(th1d^2 + th2d^2 + th3d^2 + th4d^2 + th5d^2))/2 + (l1_Izz*th1d^2)/2 - g*m3*(l2*sin(th2) + (l3*cos(th2)*cos(th3))/2) - g*m5*(l2*sin(th2) + l3*cos(th2)*cos(th3) - l4*cos(th2)*cos(th3)*sin(delta - th4) - (l5*cos(th2)*cos(th3)*sin(delta - th4))/2) - g*m4*(l2*sin(th2) + l3*cos(th2)*cos(th3) - (l4*cos(th2)*cos(th3)*sin(delta - th4))/2) - (g*l2*m2*sin(th2))/2
 

%% Use of Euler-Lagrange function:
X   = {th1 th1d th2 th2d th3 th3d th4 th4d th5 th5d};
Q_i = {beta1*th1d beta2*th2d beta3*th3d beta4*th4d beta5*th5d}; 
Q_e = {tau1 tau2 tau3 tau4 tau5};
par = {l1 l2 l3 l4 l5 m1 m2 m3 m4 m5 delta l1_Izz l2_Izz l3_Izz l4_Izz l5_Izz g beta1 beta2 beta3 beta4 beta5}
R = 0;
VF  = EulerLagrange(L,X,Q_i,Q_e,R,par,'m');
%%

syms th1 th1d th2 th2d g m1 l1 m2 l2
L   = (m1*l1^2*th1d^2 + ...
       m2*(l1^2*th1d^2 + l2^2*th2d^2 + 2*l1*l2*th1d*th2d*cos(th1 - th2)))/2 + ...
      (m1 + m2)*g*l1*cos(th1) + m2*g*l2*cos(th2);
X   = {th1 th1d th2 th2d};
Q_i = {0 0}; Q_e = {0 0};
R   = 0;
par = {g m1 l1 m2 l2};
VF  = EulerLagrange(L,X,Q_i,Q_e,R,par,'s');








% %% Euler-Lagrange Equation:
% 
% %th1:
% eq1 = diff(diff(L,th1d),t) - diff(L,th1) + beta1*th1d;
% eq1 = simplify(eq1);
% %th2:
% eq2 = diff(diff(L,th2d),t) - diff(L,th2) + beta2*th2d;
% eq2 = simplify(eq2);
% %th3:
% eq3 = diff(diff(L,th3d),t) - diff(L,th3) + beta3*th3d;
% eq3 = simplify(eq3);
% %th4:
% eq4 = diff(diff(L,th4d),t) - diff(L,th4) + beta4*th4d;
% eq4 = simplify(eq4);
% %th5:
% eq5 = diff(diff(L,th5d),t) - diff(L,th5) + beta5*th5d;
% eq5 = simplify(eq5);
% 

%% Solve equation:
% q1 = isolate(eq1, diff(th1, t, t));
% q2 = isolate(eq2, diff(th2, t, t));
% q3 = isolate(eq3, diff(th3, t, t));
% q4 = isolate(eq4, diff(th4, t, t));
% q5 = isolate(eq5, diff(th5, t, t));






%%