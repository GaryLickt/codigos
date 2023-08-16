/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "Room1"{
n = 0
a = -1375;
var backid = layer_get_id("Background");
var back2id = layer_get_id("Backgrounds_1");
var back3id = layer_get_id("Backgrounds_2");

var layid = layer_background_get_id(backid);
var lay2id = layer_background_get_id(back2id);
var lay3id = layer_background_get_id(back3id);
veloc = ((oSpawner.runcenario)*-1);
veloc2 = ((oSpawner.runcenario2)*-1);
veloc3 = ((oSpawner.runcenario3)*-1);

if oMainConquistas.desafio_on = false {
	switch(global.level){
	case 1: layer_background_change(layid,spr_background1);layer_background_change(lay2id,spr_background1_2);layer_background_change(lay3id,spr_background1_3);break;
	case 2: layer_background_change(layid,choose(spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2,spr_background2banner2,spr_background2banner3,spr_background2banner4,spr_background2banner5,spr_background2banner6));layer_background_change(lay2id,spr_background2_2);layer_background_change(lay3id,spr_background2_3);break;
	case 3: layer_background_change(layid,spr_background1);break;
	case 4: layer_background_change(layid,spr_background1);break;
	case 5: layer_background_change(layid,spr_background1);break;
	}
}
}
if room_get_name(room) = "RoomMenu" {
	if oDoly.sprite_index = spr_curseddoly {
	var backid = layer_get_id("Background");
	var layid = layer_background_get_id(backid);
	layer_background_change(layid,spr_menuground3);
	}
}