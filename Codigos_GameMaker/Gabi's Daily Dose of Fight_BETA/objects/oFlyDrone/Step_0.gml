speed = oSpawner.run + 2;

depth = -y;

if oGabi.estado == scr_player_run {
var _dash = instance_create_layer(x, y, "Instances", oDash);
_dash.sprite_index = sprite_index;
}

y = startY + (sin(current_time/waveTime) * waveHeight)

instance_create_layer(x,y,"Instances",oWhiteRay);