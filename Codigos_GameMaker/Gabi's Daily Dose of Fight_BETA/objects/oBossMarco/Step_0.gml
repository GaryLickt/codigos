/// @description Insert description here
// You can write your code in this editor
if stop = false {
x += dir
y += yir
}

if (x >= Xmax) or (x<= Xmin){
dir = dir * -1
}

if (y >= Ymax) or (y<= Ymin){
yir = yir * -1
}

if atk3 = true {
	if random_range(0,10) <= 2 {
		audio_play_sound(snd_ded,1,0);
		var up = instance_create_layer(x,y-64,"Instances",choose(oBossMarcoRedShot,oBossMarcoRedDente));
		up.speed = 6;
		up.direction = point_direction(x, y, x+irandom_range(-1,1), y-1);
		up.image_angle = point_direction(x, y, x+irandom_range(-1,1), y-1);
	}
}
if oping = true {
	if random_range(0,10) <= 8 {
		var fall = instance_create_layer(irandom_range(0,room_width),0,"Instances",choose(oBossMarcoRedShot,oBossMarcoRedDente,oBossMarcoRedShot,oBossMarcoRedShot,oBossMarcoRedShot,oBossMarcoRedShot,oBossMarcoRedShot,oBossMarcoRedShot,oBossMarcoRedShot,oBossMarcoRedShot));
		fall.speed = 6;
		fall.direction = point_direction(x, y, x, y+1);
		fall.image_angle = point_direction(x, y, x, y+1);
	}
}

if (stage = 2) and (stop = false) {
var d = instance_create_layer(x,y,"Instances",oDash);
	d.spd = 0.02;
	d.sprite_index = sprite_index;
	d.image_alpha = 0.5;
}

ticks = floor(hp/30);

if hp < 30 {
sprite_index = spr_marcoBossScared;
}

if hp <= 0 {
stop = true;
sprite_index = spr_marcoBossDestroy;
}

if oGabiBoss1.dead = true {
stop = true;
sprite_index = spr_marcoBossGGEZ;
}