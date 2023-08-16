/// @description Insert description here
// You can write your code in this editor
var Xpos = oGabiBoss1.x;
var Ypos = oGabiBoss1.y;

var p1 = instance_create_layer(x,y,"Instances", oShootRobotPurpleMissel);
p1.speed = 2;
p1.direction = point_direction(x,y,Xpos-25,Ypos);
p1.image_angle = point_direction(x,y,Xpos-25,Ypos);

var p2 = instance_create_layer(x,y,"Instances", oShootRobotPurpleMissel);
p2.speed = 2;
p2.direction = point_direction(x,y,Xpos+25,Ypos);
p2.image_angle = point_direction(x,y,Xpos+25,Ypos);

var p3 = instance_create_layer(x,y,"Instances", oShootRobotPurpleMissel);
p3.speed = 2;
p3.direction = point_direction(x,y,Xpos,Ypos);
p3.image_angle = point_direction(x,y,Xpos,Ypos);


instance_destroy();
