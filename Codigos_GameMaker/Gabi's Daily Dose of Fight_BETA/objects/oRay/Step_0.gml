var pai = place_meeting(x, y-1, oFlyObstacle);

if oGabi.estado == scr_player_run {
var _dash = instance_create_layer(x, y, "Instances", oDash);
_dash.sprite_index = sprite_index;
}

if !pai {
instance_destroy();
}

depth = -y;