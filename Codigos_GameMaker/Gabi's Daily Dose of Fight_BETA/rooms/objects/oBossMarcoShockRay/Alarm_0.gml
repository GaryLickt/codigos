/// @description Insert description here
// You can write your code in this editor
var a = instance_create_layer(x,y,"Instances",oBossMarcoShockWave);
a.speed = 3;
a.direction = choose(irandom_range(90,180),irandom_range(270,360));
alarm[0] = 30;