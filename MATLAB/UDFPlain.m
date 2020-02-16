% time=1;
% velocity=.00001*time^3-0.00488*time^2+0.75795*time+181.3566;
% acceleration=3-0.000062*velocity^2;
hold on;
index=1;
for time=0:10:130
    velocity(index) = (.00001*time^3-0.00488*time^2+0.75795*time+181.3566);
    acceleration(index)=3-0.000062*velocity(index)^2;
    %disp(index);
    index=index+1;
end
data={0, acceleration(1), velocity(1); 10, acceleration(2), velocity(2);20, acceleration(3), velocity(3);30, acceleration(4), velocity(4);40, acceleration(5), velocity(5);50, acceleration(6), velocity(6);60, acceleration(7), velocity(7);70, acceleration(8), velocity(8);80, acceleration(9), velocity(9);90, acceleration(10), velocity(10);100, acceleration(11), velocity(11);110, acceleration(12), velocity(12);120, acceleration(13), velocity(13)};
columnname={"Time","Acceleration","Velocity"};
table=uitable('Units', 'normalized','Position',[.1 .1 1.9 .9], 'Data', data,'Columnname', columnname);