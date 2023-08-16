/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "Room1"{
	x = 285;
	y = 288;
}
if room_get_name(room) = "RoomBoss1"{
		if (oBossMarco.hp > 0) and (oGabiBoss1.dead != true) {
			if instance_exists(oBombCollision) {
				desvi = choose(-1,1);
			}else{
			desvi = 0;
			}
	
			if oGabiBoss1.estado != scr_player_boss_ded {
				x = lerp(x,(oGabiBoss1.x),0.05)+desvi;
				y = lerp(y,(oGabiBoss1.y-100),0.05)+desvi;
			}
		}else{
			x = lerp(x,room_width/2,0.05)+desvi;
			if oGabiBoss1.estado != scr_player_boss_ded {
				y = lerp(y,(oGabiBoss1.y-100),0.05)+desvi;
			}
		}
}
if room_get_name(room) = "RoomBoss2"{
	
	if instance_exists(oBombCollision) {
		desvi = choose(-1,1);
	}else{
	desvi = 0;
	}
	
	if (oGabiBoss2.estado != scr_player_boss2_ded) or (oBossShadow.hp <= 0) {
		if point_distance(oGabiBoss2.x,oGabiBoss2.y, oBossShadow.x, oBossShadow.y) > 200 {
		x = lerp(x,(oGabiBoss2.x),0.05)+desvi;
		y = lerp(y,(oGabiBoss2.y),0.05)+desvi;
		}else{
		x = lerp(x,(oBossShadow.x),0.05)+desvi;
		y = lerp(y,(oBossShadow.y),0.05)+desvi;
		}
	}else{
	x = lerp(x,room_width/2,0.05);
	y = lerp(y,room_height/2,0.05);
	}
}
	
if room_get_name(room) = "RoomSelector"{
	camera_set_view_pos(view_camera[0],cam,ypos)
}