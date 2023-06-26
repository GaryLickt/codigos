/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "Room1"{
	x = 285;
	y = 288;
}
if room_get_name(room) = "RoomBoss1"{
	
	if instance_exists(oBombCollision) {
		desvi = choose(-1,1);
	}else{
	desvi = 0;
	}
	
	if oGabiBoss1.estado != scr_player_boss_ded {
		x = lerp(x,(oGabiBoss1.x),0.05)+desvi;
		y = lerp(y,(oGabiBoss1.y-100),0.05)+desvi;
	}
}
	
if room_get_name(room) = "RoomSelector"{
	camera_set_view_pos(view_camera[0],cam,ypos)
}