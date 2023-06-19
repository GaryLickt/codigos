/// @description Head Attack Starts
// You can write your code in this editor
if oGabiBoss1.dead = false {
if hp >= 30 {
if prio = 4 {
if (atk2 = false) and (atk3 = false) {
	if (distance_to_point(oGabiBoss1.x, y) <= 100) and (stop = false) {
		stop = true;
		instance_create_layer(x, y, "Instances", oBossMarcoShockRayMain);

		sprite_index = spr_marcoBossRay;
		atk4 = true;
		alarm[7] = 60;
	}else{
		alarm[6] = 200;
	}
}
prio = choose(2,3,4,4)
alarm[1] = choose(80,160,240);
alarm[2] = choose(80,160,240);
alarm[6] = choose(80,160,240);
}
}
}