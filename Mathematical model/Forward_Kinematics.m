%% Forward Kinematics for the Big Arm:
syms th1 th2 th3 th4 th5
syms lb1 l1 l2 l3 l4 l5
syms pi
% Calibration values:
%th1 = 1.36; th2 = 1.14; th3 = -1.99; th4 = 2.73; th5 = 3.37;
%lb1 = 0.025; l1 = 0.110; l2 = 0.38; l3 = 0.38; l4 = 0.38; l5 = 0.04;
%% From B to 1:

T_1_B = [eye(3), [0; 0; lb1];
    0, 0, 0, 1];

R_1_B = eye(3);


%% From 1 to 2:
%p = sym(pi);
Rz21 = [
  cos(th1), -sin(th1), 0;
  sin(th1), cos(th1), 0;
  0, 0, 1;
];

Ru21 = [1, 0, 0;
    0, cos(-pi/2), -sin(-pi/2);
    0, sin(-pi/2), cos(-pi/2);
];

Rv21 = [cos(pi), 0, sin(pi);
    0, 1, 0;
    -sin(pi), 0, cos(pi)
];


R_2_1 = vpa(Rz21*Ru21*Rv21);

T_2_1 = [R_2_1, [0; 0; l1];
  0, 0, 0, 1  
];

T_2_B = T_1_B*T_2_1;

%% From 2 to 3:

T_3_2 = [cos(-pi/2+th2), -sin(-pi/2+th2), 0, l2*cos(th2);
    sin(-pi/2+th2), cos(-pi/2+th2), 0, l2*sin(th2);
    0, 0, 1, 0;
    0, 0, 0, 1
];

R_3_2 = [
    cos(-pi/2+th2), -sin(pi/2+th2), 0;
    sin(-pi/2+th2), cos(-pi/2+th2), 0;
    0, 0, 1
];

T_3_B = T_1_B*T_2_1*T_3_2;

%% From 3 to 4:
T_4_3 = [cos(-pi/2+th3), -sin(-pi/2+th3), 0, l3*cos(th3);
    sin(-pi/2+th3), cos(-pi/2+th3), 0, l3*sin(th3);
    0, 0, 1, 0;
    0, 0, 0, 1
];

R_4_3 = [
  cos(-pi/2+th3), -sin(-pi/2+th3), 0;
  sin(-pi/2+th3), cos(-pi/2+th3), 0;
  0, 0, 1;
];

T_4_B = T_1_B*T_2_1*T_3_2*T_4_3;

%% From 4 to 5:

T_5_4 = [
    cos(pi-th4), -sin(pi-th4), 0, l4*cos(th4);
    sin(pi-th4), cos(pi-th4), 0, l4*sin(th4);
    0, 0, 1, 0;
    0, 0, 0, 1;
];

R_5_4 = [
  cos(pi-th4), -sin(pi-th4), 0;
  sin(pi-th4), cos(pi-th4), 0;
  0, 0, 1;
];



%% Test B to 2: OK :)

%P2_2 = [l2*cos(th2); l2*sin(th2); 0; 1];

%P2_B = T_1_B*T_2_1*P2_2

%% Test B to 3: OK :)

%P3_3 = [l3*cos(th3); l3*sin(th3); 0; 1];

%P3_B = T_3_B*P3_3

%% Test B to 4: OK :)

%P_4_4 = [l4*cos(th4); l4*sin(th4); 0; 1];
%P_4_B = T_1_B*T_2_1*T_3_2*T_4_3*P_4_4;

%% Test B to 5: OK

%P_6_5 = [-l5*cos(th5); -l5*sin(th5); 0; 1];

%P_6_B = vpa(T_1_B*T_2_1*T_3_2*T_4_3*T_5_4*P_6_5, 6);








