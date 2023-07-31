/// @description Health State Checker
// You can write your code in this editor
if oGabiBoss1.dead = false {
alarm[9] = 1;

if ((hp >= 0) and (hp <=150)) and (stage != 2) {
	stage = 2;
	extra_hp += 75;
	var d = instance_create_layer(x,y,"Instances",oDash);
	d.image_xscale = 1.5;
	d.image_yscale = 1.5;
	d.spd = 0.02;
	d.sprite_index = sprite_index;
	d.image_alpha = image_alpha;
	alarm[10] = 60 * ticks;
}
}