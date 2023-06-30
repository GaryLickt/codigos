/// @description Insert description here
// You can write your code in this editor
image_angle += dir;

ray = instance_create_layer(x,y,"Instances",oWhiteRay);
ray.image_xscale = 0.5;
ray.image_yscale = 0.5;

if room_get_name(room) = "Room1" {
if oGabi.estado = scr_player_ded {
ray.speed = speed;
ray.direction = direction
instance_destroy();
}
}
if room_get_name(room) = "RoomBoss1" {
if oGabiBoss1.estado = scr_player_boss_ded {
ray.speed = speed;
ray.direction = direction
instance_destroy();
}
}
if room_get_name(room) = "RoomBoss2" {
if oGabiBoss2.estado = scr_player_boss2_ded {
ray.speed = speed;
ray.direction = direction
instance_destroy();
}
}