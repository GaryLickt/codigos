/// @description Insert description here
// You can write your code in this editor

image_speed = startspeed;

if oGabiBoss1.dead = false {
if image_xscale = 1 {
var shot = instance_create_layer(x+9, y-47,"Instances",oShootRobotPurpleShot);
shot.speed = 4;
shot.direction = point_direction(x,y,x+1,y-2)
}else{
var shot = instance_create_layer(x-9, y-47,"Instances",oShootRobotPurpleShot);
shot.speed = 4;
shot.direction = point_direction(x,y,x-1,y-2)
}
alarm[0] = 300;
}