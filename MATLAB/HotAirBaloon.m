%F = total force
%FsubX = force in the x direction
%FsubY = force in the Y direction
%sin (thata)=FsubY/F
%FsubY = Fsin(thata)
%FsubX = Fcos(thata)
%angle of movement = tan^-1(FsubY/FsubX)
%baloon 200N up and 100N down with a wind of 50N at 30degrees
Boyancy=200;
Graverty=100;
windX=50*cosd(30);
windY=50*sind(30);
FsubXtotal=windX;
FsubYtotal=(Boyancy-Graverty)+windY;
direction=atand((FsubYtotal/FsubXtotal));
magnatude=FsubXtotal/cosd(direction);
disp("magnatude " + magnatude + " direction " + direction);