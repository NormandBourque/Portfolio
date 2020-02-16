%x=displacement @ time t
%A=maximum displacement
%w=angular frequency, which depends on the spring constant and the mass
%  attached to the spring
%t=time
%t=0 to 10
%A=4cm
%w=0.6
%a=-Aw^2*cos(wt)
%x=Acos(wt)
t=1:10;
A=4;
w=0.6;
a=-A*w^2*cos(w*t);
x=A*cos(w*t);
hold on;
plot(t,a);
plot(t,x);
legend('a=-A*w^2*cos(w*t)','x=A*cos(w*t)');
xlabel('time(sec)');
ylabel('displacement and acceleration(cm)');
title('The displacement of the oscillating spring');