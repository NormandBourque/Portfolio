%R(theta) = (v.^2/g)*sin(2*theta) for 0<=theta<=pi/2
%g=9.9 v=50 then 100 m/s from theta = 0 to pi/2 by .05

g=9.9;
v=50;
theta = 0:.05:pi/2;
Rtheta=mtimes((v.^2/g),sin(2*theta));
plot(theta, Rtheta);

hold on;

v=100;
theta = 0:.05:pi/2;
Rtheta=mtimes((v.^2/g),sin(2*theta));
plot(theta, Rtheta);
legend("@ 50","@ 100")

