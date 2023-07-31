/// @description Pulse Effect every 5s
// You can write your code in this editor
if oGabiBoss1.dead = false {
if hp > 0 {
	ulti = true;
var d = instance_create_layer(x,y,"Instances",oDash);
d.image_xscale = 2;
d.image_yscale = 2;
d.sprite_index = sprite_index;
d.image_alpha = 0.6;
d.spd = 0.02;
if hp >= 30 {
alarm[10] = 60 * ticks;
}else{
alarm[10] = 30;
}

	var shot = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot.image_xscale = 2;
	shot.image_yscale = 2;
	shot.direction = 0+choose(-20,0,20);
	shot.speed = 4;
	
	var shot1 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot1.image_xscale = 2;
	shot1.image_yscale = 2;
	shot1.direction = 90+choose(-20,0,20);
	shot1.speed = 4;
	
	var shot2 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot2.image_xscale = 2;
	shot2.image_yscale = 2;
	shot2.direction = 180+choose(-20,0,20);
	shot2.speed = 4;
	
	var shot3 = instance_create_layer(x, y, "Instances", oBossMarcoRedShot);
	shot3.image_xscale = 2;
	shot3.image_yscale = 2;
	shot3.direction = 270+choose(-20,0,20);
	shot3.speed = 4;
	
	ulti = false;
}
}