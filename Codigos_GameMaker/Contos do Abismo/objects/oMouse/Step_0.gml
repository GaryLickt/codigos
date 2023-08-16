/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "RoomMenu" {
image_xscale = 1;
image_yscale = 1;
}else{
instance_destroy();
}

x = mouse_x;
y = mouse_y;

depth = -1000;

