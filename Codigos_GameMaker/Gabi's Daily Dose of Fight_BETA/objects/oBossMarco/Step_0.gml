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

if stop = true {
	if random_range(0,10) <= 2 {
		var up = instance_create_layer(x,y-64,"Instances",choose(oBossMarcoRedShot,oBossMarcoRedDente));
		up.speed = 6;
		up.direction = point_direction(x, y, x+irandom_range(-1,1), y-1);
		up.image_angle = point_direction(x, y, x+irandom_range(-1,1), y-1);
	}
}
if oping = true {
	if random_range(0,10) <= 8 {
		var fall = instance_create_layer(irandom_range(0,room_width),0,"Instances",choose(oBossMarcoRedShot,oBossMarcoRedDente));
		fall.speed = 6;
		fall.direction = point_direction(x, y, x, y+1);
		fall.image_angle = point_direction(x, y, x, y+1);
	}
}