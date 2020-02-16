%o=F/A
%e=(l-lsub0)/lsub0
%o is the stress in lbsubF/in^2(psi)
%F is the applied force in lbs
%A is sample cross-section area in in^2
%e is strain in in./in
%l is sample length
%lsub0 is original sample length
%   load,lbf(pounds per foot)   length
%   0                           2
%   1650                        2.002
%   3400                        2.004
%   5200                        2.006
%   6850                        2.008
%   7750                        2.010
%   8650                        2.020
%   9300                        2.040
%   10100                       2.080
%   10400                       2.120

F=[0 1650 3400 5200 6850 7750 8650 9300 10100 10400];
l=[2 2.002 2.004 2.006 2.008 2.010 2.020 2.040 2.080 2.120];
lsub0=l(1);
diamiter=0.505;
r=diamiter/2;
A=pi*r^2;
o=F/A;
e=(l-lsub0)/lsub0;
plot(e,o,"-ok");
title('Stress-Strain Curve');
xlabel("Strain");
ylabel("Stress");
textx=[0.3 0.19];
texty=[0.5 0.63];
text='Yeld point';
annotation('textarrow',textx,texty,'String','yield point');