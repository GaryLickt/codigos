/// @description Insert description here
// You can write your code in this editor
if (oMainControl.level_map[# oCamera.stage-1, 0] >= 1) and (oMainControl.level_map[# oCamera.stage-1, 0] < 7) {
	if place_meeting(x,y,oMouseCollision){
		if oMainControl.level_map[# oCamera.stage-1, 0] <= 5 {
			var trans = instance_create_depth(0,0,-9000,oTransicao);
			instance_create_depth(0,room_height,-9000,oTransicaoDown);
			trans.sala = Room1;
			global.level = oCamera.stage;
			global.fase = oMainControl.level_map[# oCamera.stage-1, 0];
		}else {
		switch(global.level){
			case 1: var trans = instance_create_depth(0,0,-9000,oTransicao);
					instance_create_depth(0,room_height,-9000,oTransicaoDown);
					trans.sala = RoomBoss1;break;
			case 2: var trans = instance_create_depth(0,0,-9000,oTransicao);
					instance_create_depth(0,room_height,-9000,oTransicaoDown);
					trans.sala = RoomBoss2;break;
		}
		global.level = oCamera.stage;
		global.fase = oMainControl.level_map[# oCamera.stage-1, 0];
		}
		audio_stop_all();
	}
}