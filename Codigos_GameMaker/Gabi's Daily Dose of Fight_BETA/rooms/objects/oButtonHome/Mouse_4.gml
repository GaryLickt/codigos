/// @description Insert description here
// You can write your code in this editor
if place_meeting(x,y,oMouseCollision){
	if oMainConquistas.desafio_on = false {
	var trans = instance_create_depth(0,0,-9000,oTransicao);
	instance_create_depth(0,room_height,-9000,oTransicaoDown);
	trans.sala = RoomSelector;
	oCamera.stage = global.level;
	oCamera.cam = (oCamera.stage-1)*1377;
	if room_get_name(room) = "Room1" {
		if (oControl.passou = true) {
			if variable_global_get("fase") = 6 {
				variable_global_set("fase",1);
				oMainControl.level_map[# variable_global_get("level")-1, 0] = 7;
				variable_global_set("level",(variable_global_get("level")+1));
			}else{
				// Caso contrario, avança para a proxima fase
				variable_global_set("fase",(variable_global_get("fase")+1));
			}
				// Atualiza a Fase mais alta alcançado por mundo
			if variable_global_get("fase") > oMainControl.level_map[# variable_global_get("level"), 0] {
				oMainControl.level_map[# variable_global_get("level")-1, 0] = variable_global_get("fase");
			}
			if variable_global_get("level") > variable_global_get("highlevel") {
				variable_global_set("highlevel",variable_global_get("level"));
			}
		}
	}
	if room_get_name(room) = "RoomBoss1" {
		if (oBossMarco.hp <= 0) {
			if variable_global_get("fase") = 6 {
				variable_global_set("fase",1);
				oMainControl.level_map[# variable_global_get("level")-1, 0] = 7;
				variable_global_set("level",(variable_global_get("level")+1));
			}else{
				// Caso contrario, avança para a proxima fase
				variable_global_set("fase",(variable_global_get("fase")+1));
			}
				// Atualiza a Fase mais alta alcançado por mundo
			if variable_global_get("fase") > oMainControl.level_map[# variable_global_get("level"), 0] {
				oMainControl.level_map[# variable_global_get("level")-1, 0] = variable_global_get("fase");
			}
			if variable_global_get("level") > variable_global_get("highlevel") {
				variable_global_set("highlevel",variable_global_get("level"));
			}
		}
	}
	audio_stop_all();
	}else{
	var trans = instance_create_depth(0,0,-9000,oTransicao);
	instance_create_depth(0,room_height,-9000,oTransicaoDown);
	trans.sala = RoomMenuDesafio;
	oMainConquistas.desafio_on = false;
	oMainConquistas.qual_desafio = "";
	audio_stop_all();
	}
}