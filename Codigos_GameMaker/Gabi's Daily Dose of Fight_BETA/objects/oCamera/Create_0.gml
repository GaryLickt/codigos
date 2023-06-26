/// @description Insert description here
// You can write your code in this editor
randomize();

if room_get_name(room) = "Room1"{
	x = 285;
	y = 288;
}

if room_get_name(room) = "RoomBoss1"{
	x = oGabiBoss1.x;
	y = oGabiBoss1.y-100;
}
ypos = camera_get_view_y(view_camera[0])
desvi = 0;
cam = 0;
stage = 1;