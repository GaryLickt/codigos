/// @description Snake Attack
// You can write your code in this editor
if oGabiBoss1.dead = false {
if atk2 = true {
	var shot = instance_create_layer(x-44, y+38, "Instances", oBossMarcoRedDente);
	shot.direction = point_direction(x, y, oGabiBoss1.x, oGabiBoss1.y);
	shot.image_angle = point_direction(x, y, oGabiBoss1.x, oGabiBoss1.y);
	shot.speed = 2;
	
	var shot1 = instance_create_layer(x-25, y+31, "Instances", oBossMarcoRedDente);
	shot1.direction = point_direction(x, y, oGabiBoss1.x, oGabiBoss1.y);
	shot1.image_angle = point_direction(x, y, oGabiBoss1.x, oGabiBoss1.y);
	shot1.speed = 2;
	alarm[5] = 30;
}
}