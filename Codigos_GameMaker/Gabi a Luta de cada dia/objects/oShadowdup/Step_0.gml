speed = oSpawner.run
vspd = vspd + grv;

if place_meeting(x, y + vspd, oShadowddown) {
	while(!place_meeting(x, y + sign(vspd), oShadowddown)){
		y+=sign(vspd)
	}
	vspd = 0;
	if alarm[0] <= 0 {
		alarm[0] = 30;
	}
}
y+= vspd;

depth = -y;
