/// @description Insert description here
// You can write your code in this editor
var direc = (direction+180);

var s1 = instance_create_layer(x,y,"Instances",oBossShadowMinidia);
s1.speed = 3;
s1.direction = direc + 20;
s1.image_angle = direc + 20;

var s2 = instance_create_layer(x,y,"Instances",oBossShadowMinidia);
s2.speed = 3;
s2.direction = direc - 20;
s2.image_angle = direc - 20;

alarm[0] = 15;