/// @description Insert description here
// You can write your code in this editor
if (stop = false) and (oping = false) {
	var shot = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot.direction = 0+choose(-20,0,20);
	shot.speed = 4;
	
	var shot1 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot1.direction = 45+choose(-20,0,20);
	shot1.speed = 4;
	
	var shot2 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot2.direction = 90+choose(-20,0,20);
	shot2.speed = 4;
	
	var shot3 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot3.direction = 135+choose(-20,0,20);
	shot3.speed = 4;
	
	var shot4 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot4.direction = 180+choose(-20,0,20);
	shot4.speed = 4;
	
	var shot5 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot5.direction = 225+choose(-20,0,20);
	shot5.speed = 4;
	
	var shot6 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot6.direction = 270+choose(-20,0,20);
	shot6.speed = 4;
	
	var shot7 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot7.direction = 315+choose(-20,0,20);
	shot7.speed = 4;
}
alarm[0] = choose(5,30,60,120);