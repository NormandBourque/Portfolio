%height = 2.13t^2 - 0.0013t^4 + 0.000034t^4.751
hold on;
index = 1;
height=zeros(1,50);
disp(height);
for time=0:2:100
    height(index)=2.13*time^2-0.0013*time^4+0.000034*time^4.751;
    index = index + 1;
end

data={0, height(1); 2, height(2); 4, height(3); 6, height(4); 8, height(5); 10, height(6); 12, height(7); 14, height(8); 16, height(9); 18, height(10); 20, height(11); 22, height(12); 24, height(13); 26, height(14); 28, height(15); 30, height(16); 32, height(17); 34, height(18); 36, height(19); 38, height(20); 40, height(21); 42, height(22); 44, height(23); 46, height(24); 48, height(25); 50, height(26); 52, height(27); 54, height(28); 56, height(29); 58, height(30); 60, height(31); 62, height(32); 64, height(33); 66, height(34); 68, height(35); 70, height(36); 72, height(37); 74, height(38); 76, height(39); 78, height(40); 80, height(41); 82, height(42); 84, height(43); 86, height(44); 88, height(45); 90, height(46); 92, height(47); 94, height(48); 96, height(49); 98, height(50); 100, height(51)}; 
columnname={'Time', 'Height'};
[maxHeight, maxIndex] = max(height(:));
table=uitable('Units', 'normalized','Position',[.1 .1 1.9 .9], 'Data', data,'Columnname', columnname);
disp("Max height = " + maxHeight + " at index " + maxIndex);