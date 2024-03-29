%% Lagrange Mathematical Model:

% WARNING: RUN THE FORWARD_KINEMATICS.M CODE FIRST TO LOAD THE REQUIRED WORKSPACE!
syms lb1 l1 l2 l3 l4 l5
syms m1 m2 m3 m4 m5
syms g
syms u1 u2 u3 u4 u5
syms beta1 beta2 beta3 beta4 beta5
syms tau1 tau2 tau3 tau4 tau5 
syms Ixx1 Ixy1 Ixz1 Iyx1 Iyy1 Iyz1 Izx1 Izy1 Izz1
syms Ixx2 Ixy2 Ixz2 Iyx2 Iyy2 Iyz2 Izx2 Izy2 Izz2
syms Ixx3 Ixy3 Ixz3 Iyx3 Iyy3 Iyz3 Izx3 Izy3 Izz3
syms Ixx4 Ixy4 Ixz4 Iyx4 Iyy4 Iyz4 Izx4 Izy4 Izz4
syms Ixx5 Ixy5 Ixz5 Iyx5 Iyy5 Iyz5 Izx5 Izy5 Izz5


%% Parameters:
% lb1 = 0.025; l1 = 0.110; l2 = 0.38; l3 = 0.38, l4 = 0.38; l5 = 0.04;
% pi = 3.14159; beta1 = 0.3; beta2 = 0.1; beta3 = 0.1; beta4 = 0.1; beta5 = 0.1;
% g = 9.81; 
% m1 = 2.24036; m2 = 1.380584; m3 = 0.4927734;
% m4 = 1.380584; m5 = 0.130378439395373;
% % Inertia Tensor 1:
% Ixx1 = 0.00602313752636761; Ixy1 = 2.1208125474502E-05; Ixz1 = 0;
% Iyx1 = -Ixy1; Iyy1 = 0.00579248437417585; Iyz1 = 0;
% Izx1 = -Ixz1; Izy1 = -Iyz1; Izz1 = 0.0098329939500295;
% 
% % Inertia Tensor 2:
% Ixx2 = 0.00248849839; Ixy2 = 0; Ixz2 = 0;
% Iyx2 = -Ixy2; Iyy2 = 0.043747624; Iyz2 = 0;
% Izx2 = -Ixz2; Izy2 = -Iyz2; Izz = 0.0425687;
% 
% % Intertia Tensor 3:
% Ixx3 = 0.000993126; Ixy3 = 0; Ixz3 = 0;
% Iyx3 = -Ixy3; Iyy3 = 0.0088282898; Iyz3 = 0;
% Izx3 = -Ixz3; Izy3 = -Iyz3; Izz3 = 0.008576398866;
% 
% % Intertia Tensor 4:
% Ixx4 = 0.00312638; Ixy4 = 0.00354785; Ixz4 = 0.0035964956;
% Iyx4 = -Ixy4; Iyy4 = 0.0434376808; Iyz4 = -0.00032350627;
% Izx4 = -Ixz4; Izy4 = -Iyz4; Izz4 = 0.042240781;
% 
% % Intertia Tensor 5:
% Ixx5 = 9.85693744749924E-05; Ixy5 = 0; Ixz5 = 0;
% Iyx5 = -Ixy5; Iyy5 = 0.00011697309; Iyz5 = 0;
% Izx5 = -Ixz5; Izy5 = -Iyz5; Izz5 = 0.0001866513337855;

% Inertia Tensors:

I1 =  [
    Ixx1, Ixy1, Ixz1;
    Iyx1, Iyy1, Iyz1;
    Izx1, Izy1, Izz1
];

I2 = [
    Ixx2, Ixy2, Ixz2;
    Iyx2, Iyy2, Iyz2;
    Izx2, Izy2, Izz2
];

I3 = [
    Ixx3, Ixy3, Ixz3;
    Iyx3, Iyy3, Iyz3;
    Izx3, Izy3, Izz3
];

I4 = [
    Ixx4, Ixy4, Ixz4;
    Iyx4, Iyy4, Iyz4;
    Izx4, Izy4, Izz4
];

I5 = [
    Ixx5, Ixy5, Ixz5;
    Iyx5, Iyy5, Iyz5;
    Izx5, Izy5, Izz5
];


%% Positions:
% Link 1:
x1 = 0; y1 = 0; z1 = lb1 + l1/2;


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
x1 = 0; y1 = 0; z1 = l1/2+lb1;
P1 = [x1; y1; z1];

% Link 2:
x2 = 0.5*l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 0.5*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y2 = 0.5*l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + 0.5*l2*cos(0.5*pi)*cos(th1)*sin(th2);
z2 = l1 + lb1 - 0.5*l2*sin(0.5*pi)*sin(th2) - 0.5*l2*cos(0.5*pi)*cos(th2)*sin(pi);
P2 = [x2; y2; z2];

% Link 3:
x3 = 0.5*l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2)) + 0.5*l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1)) + l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y3 = 0.5*l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2)) + 0.5*l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
z3 = l1 + lb1 - 0.5*l3*sin(th3)*(1.0*sin(0.5*pi)*cos(0.5*pi - 1.0*th2) + 1.0*cos(0.5*pi)*sin(pi)*sin(0.5*pi - 1.0*th2)) - 1.0*l2*sin(0.5*pi)*sin(th2) + 0.5*l3*cos(th3)*(1.0*sin(0.5*pi)*sin(0.5*pi - 1.0*th2) - 1.0*cos(0.5*pi)*sin(pi)*cos(0.5*pi - 1.0*th2)) - 1.0*l2*cos(0.5*pi)*cos(th2)*sin(pi);
P3 = [x3; y3; z3];

% Link 4:
x4 = 0.5*l4*sin(th4)*(sin(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2)) + cos(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1))) - 0.5*l4*cos(th4)*(1.0*sin(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1)) - cos(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2))) + l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(th1)*sin(0.5*pi - 1.0*th2)) + l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(0.5*pi)*cos(0.5*pi - 1.0*th2)*sin(th1)) + l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y4 = 0.5*l4*sin(th4)*(sin(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + cos(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2)) + 0.5*l4*cos(th4)*(cos(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) - 1.0*sin(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
z4 = 0.5*l4*sin(th4)*(sin(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + cos(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*sin(th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2)) + 0.5*l4*cos(th4)*(cos(0.5*pi - 1.0*th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) - 1.0*sin(0.5*pi - 1.0*th3)*(sin(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(0.5*pi)*cos(th1)*cos(0.5*pi - 1.0*th2))) + l3*cos(th3)*(cos(0.5*pi - 1.0*th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - 1.0*cos(0.5*pi)*cos(th1)*sin(0.5*pi - 1.0*th2)) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
P4 = [x4; y4; z4];

% Link 5:
x5 = l4*sin(th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1))) + l3*cos(th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) + l3*sin(th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) - (l5*cos(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1))) + sin(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)))))/2 - (l5*sin(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1))) - sin(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1)))))/2 + l2*cos(th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + l4*cos(th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*cos(th1) + sin(0.5*pi)*sin(pi)*sin(th1)) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(th1))) - 1.0*l2*cos(0.5*pi)*sin(th1)*sin(th2);
y5 = l3*cos(th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) + l3*sin(th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) - (l5*cos(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1))) + sin(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)))))/2 - (l5*sin(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1))) - sin(pi - th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)))))/2 + l4*cos(th4)*(cos(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1)) - sin(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1))) + l4*sin(th4)*(cos(pi/2 - th3)*(sin(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + cos(pi/2 - th2)*cos(0.5*pi)*cos(th1)) + sin(pi/2 - th3)*(cos(pi/2 - th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) - cos(0.5*pi)*sin(pi/2 - th2)*cos(th1))) + l2*cos(th2)*(cos(pi)*sin(th1) - 1.0*sin(0.5*pi)*cos(th1)*sin(pi)) + l2*cos(0.5*pi)*cos(th1)*sin(th2);
z5 = l1 + lb1 - l3*sin(th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - (l5*cos(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) + sin(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi))) - sin(pi - th4)*(cos(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - sin(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)))))/2 - 1.0*l2*sin(0.5*pi)*sin(th2) + (l5*sin(th5)*(cos(pi - th4)*(cos(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - sin(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi))) + sin(pi - th4)*(cos(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) + sin(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)))))/2 + l4*cos(th4)*(cos(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) + sin(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi))) - l4*sin(th4)*(cos(pi/2 - th3)*(1.0*cos(pi/2 - th2)*sin(0.5*pi) + 1.0*cos(0.5*pi)*sin(pi/2 - th2)*sin(pi)) - sin(pi/2 - th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi))) + l3*cos(th3)*(1.0*sin(pi/2 - th2)*sin(0.5*pi) - 1.0*cos(pi/2 - th2)*cos(0.5*pi)*sin(pi)) - 1.0*l2*cos(0.5*pi)*cos(th2)*sin(pi);
P5 = [x5; y5; z5];

%% Jacobians:


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
th1d_vec = R_1_B*[0; 0; th1d]; % Angular velocity of link 1
th2d_vec = R_1_B*R_2_1*[0; 0; th2d]; % Angular velocity of link 2
th3d_vec = R_1_B*R_2_1*R_3_2*[0; 0; th3d]; % Angular velocity of link 3
th4d_vec = R_1_B*R_2_1*R_3_2*R_4_3*[0; 0; th4d]; % Angular velocity of link 4
th5d_vec = R_1_B*R_2_1*R_3_2*R_4_3*R_5_4*[0; 0; th5d]; % Angular velocity of link 5

T1 = 0.5*m1*(x1d^2+y1d^2+z1d^2) + 0.5*th1d_vec'*I1*th1d_vec;
T2 = 0.5*m2*(x2d^2+y2d^2+z2d^2) + 0.5*th2d_vec'*I2*th2d_vec;
T3 = 0.5*m3*(x3d^2+y3d^2+z3d^2) + 0.5*th3d_vec'*I3*th3d_vec;
T4 = 0.5*m4*(x4d^2+y4d^2+z4d^2) + 0.5*th4d_vec'*I4*th4d_vec;
T5 = 0.5*m5*(x5d^2+y5d^2+z5d^2) + 0.5*th5d_vec'*I5*th5d_vec;


T = T1 + T2 + T3 + T4 + T5;
%% Potential energy:

V1 = th1*0;
V2 = m2*g*z2;
V3 = m3*g*z3;
V4 = m4*g*z4;
V5 = m5*g*z5;

V = V1 + V2 + V3 + V4 + V5;
V = V

%% Lagrangian:

L = T - V;
L = vpa(L, 6);
%% Euler-Lagrange Equation:

%th1:
eq1 = diff(diff(L,th1d),t) - diff(L,th1) + beta1*th1d == tau1;

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

diary mov_q1;
th1dd = isolate(eq1, diff(th1(t), t, t))
diary off;

diary mov_q2
th2dd = isolate(eq2, diff(th2(t), t, t));
th2dd = vpa(th2dd, 5)
diary off

diary mov_q3
th3dd = isolate(eq3, diff(th3(t), t, t));
th3dd = vpa(th3dd, 5)
diary off

diary mov_q4
th4dd = isolate(eq4, diff(th4(t), t, t));
th4dd = vpa(th4dd, 5)
diary off

diary mov_q5
th5dd = isolate(eq5, diff(th5(t), t, t));
th5dd = vpa(th5dd, 5)
diary off