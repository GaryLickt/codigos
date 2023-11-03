/// @description Insert description here
// You can write your code in this editor
if (room_get_name(room) = "RoomMenu") or (room_get_name(room) = "RoomAviso") or (room_get_name(room) = "RoomSelector") {
image_xscale = 1;
image_yscale = 1;
sprite_index = spr_mouse;
}else{
image_xscale = 0.5;
image_yscale = 0.5;
sprite_index = spr_empy;
}

x = mouse_x;
y = mouse_y;

depth = -1000;

