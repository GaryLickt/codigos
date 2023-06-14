/// @description Insert description here
// You can write your code in this editor
hp = 500;


stop = false
oping = false
randomize();
Xmax = x+400;
Xmin = x-400;

Ymax = y+25;
Ymin = y-25;

dir = choose(-1,1)*3;
yir = choose(-1,1)*1;

alarm[0] = choose(30,60,120);
alarm[1] = choose(150,300,450);
alarm[2] = 360;