/// @description Insert description here
// You can write your code in this editor
hp = 300;
extra_hp = 0;
stage = 1;
ticks = 0;

prio = 2;
atk4 = false
atk3 = false
atk2 = false
stop = false
oping = false
randomize();
Xmax = x+400;
Xmin = x-400;

Ymax = y+25;
Ymin = y-25;

dir = choose(-1,1)*3;
yir = choose(-1,1)*1;

alarm[9] = 1;
alarm[0] = choose(30,60,120);
alarm[1] = choose(80,160,240);
alarm[2] = choose(80,160,240);
alarm[6] = choose(80,160,240);