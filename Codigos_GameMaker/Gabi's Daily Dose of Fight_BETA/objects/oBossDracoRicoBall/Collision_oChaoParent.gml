/// @description Insert description here
// You can write your code in this editor
move_bounce_all(false);

var _a = instance_create_layer(x,y,"Instances",oBossDracoRicoBallSmall);
var _b = instance_create_layer(x,y,"Instances",oBossDracoRicoBallSmall);
var _c = instance_create_layer(x,y,"Instances",oBossDracoRicoBallSmall);
var _d = instance_create_layer(x,y,"Instances",oBossDracoRicoBallSmall);

_a.speed = 6;
_b.speed = 6;
_c.speed = 6;
_d.speed = 6;

_a.direction = 0;
_b.direction = 90;
_c.direction = 180;
_d.direction = 270;
