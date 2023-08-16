speed = oSpawner.run
vspd = vspd + grv;

if place_meeting(x, y + vspd, oChaoParent) {
while(!place_meeting(x, y + sign(vspd), oChaoParent)){
y+=sign(vspd)
}
vspd = 0;
sprite_index = spr_jumpobs
}
y+= vspd;

depth = -y;
