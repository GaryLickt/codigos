/// @description Insert description here
// You can write your code in this editor
if bateu = false {
speed = 0;
bateu = true;
sprite_index = spr_shadowricobombON;
if alarm[0] <= 0 {
alarm[0] = 120;
}
var a = instance_create_layer(x,y,"Instances",oBossShadowBall);
a.speed = 5;
a.direction = 90;
var a = instance_create_layer(x,y,"Instances",oBossShadowBall);
a.speed = 5;
a.direction = 180;
var a = instance_create_layer(x,y,"Instances",oBossShadowBall);
a.speed = 5;
a.direction = 270;
var a = instance_create_layer(x,y,"Instances",oBossShadowBall);
a.speed = 5;
a.direction = 0;

}

