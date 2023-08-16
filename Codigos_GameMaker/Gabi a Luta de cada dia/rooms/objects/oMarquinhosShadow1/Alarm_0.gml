/// @description Insert description here
// You can write your code in this editor
if sprite_index = spr_carshadow {
if collision_rectangle( view_xport[0], view_yport[0], view_xport[0] + view_wport[0], view_yport[0] + view_hport[0], id, false, false ) {
	var shot1 = instance_create_layer(x,y-16,"Instances",oShadowBall);
	shot1.speed = 6;
	shot1.direction = point_direction(x,y,oGabiBoss2.x, oGabiBoss2.y);
	shot1.image_angle = point_direction(x,y,oGabiBoss2.x, oGabiBoss2.y);
	
	var shot2 = instance_create_layer(x+20,y-16,"Instances",oShadowBall);
	shot2.speed = 6;
	shot2.direction = point_direction(x,y,oGabiBoss2.x+45, oGabiBoss2.y);
	shot2.image_angle = point_direction(x,y,oGabiBoss2.x+45, oGabiBoss2.y);
	
	var shot3 = instance_create_layer(x-20,y-16,"Instances",oShadowBall);
	shot3.speed = 6;
	shot3.direction = point_direction(x,y,oGabiBoss2.x-45, oGabiBoss2.y);
	shot3.image_angle = point_direction(x,y,oGabiBoss2.x-45, oGabiBoss2.y);
	alarm[0] = 100;
}else{
alarm[0] = 50;
}
}else{
alarm[0] = 50;
}