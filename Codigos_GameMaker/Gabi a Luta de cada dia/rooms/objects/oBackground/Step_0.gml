/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "Room1"{
veloc = ((oSpawner.runcenario)*-1);
layer_hspeed("Background",veloc);
veloc2 = ((oSpawner.runcenario2)*-1);
layer_hspeed("Backgrounds_1",veloc2);
veloc3 = ((oSpawner.runcenario3)*-1);
layer_hspeed("Backgrounds_2",veloc3);

if global.level = 2 {
	var backid = layer_get_id("Background");
	n = layer_get_x(backid);

	if n <= a {
		if oControl.passou == false {
			if !collision_rectangle( view_xport[0], view_yport[0], view_xport[0] + view_wport[0], view_yport[0] + view_hport[0], id, false, false ) {
				var layid = layer_background_get_id(backid);
				layer_background_change(layid,choose(spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2banner6));
				a = -1375 - (n*-1);
			}
		}
	}
}
}

if room_get_name(room) = "RoomMenu"{
	if oDoly.sprite_index = spr_curseddoly {
	var backid = layer_get_id("Background");
	var layid = layer_background_get_id(backid);
	var back2id = layer_get_id("Backgrounds_1");
	var lay2id = layer_background_get_id(back2id);
	layer_background_change(layid,spr_menuground3);
	layer_background_change(lay2id,spr_menuground4);
	var lay_id = layer_get_id("Backgrounds_2");
	var back_id = layer_background_get_id(lay_id);
	layer_background_change(back_id,spr_menuground5);
	}
layer_hspeed("Background",-4);
layer_hspeed("Backgrounds_1",-6);
}
	
if room_get_name(room) = "RoomMenuDesafio"{
layer_hspeed("Background",-4);
layer_hspeed("Backgrounds_1",-6);
}