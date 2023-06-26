/// @description Insert description here
// You can write your code in this editor
if (oMainControl.level_map[# oCamera.stage-1, 0] >= 1) and (oMainControl.level_map[# oCamera.stage-1, 0] < 7) {
	if place_meeting(x,y,oMouseCollision){
		if oMainControl.level_map[# oCamera.stage-1, 0] <= 5 {
			room_goto(Room1);
			global.level = oCamera.stage;
			global.fase = oMainControl.level_map[# oCamera.stage-1, 0];
		}else {
		switch(global.level){
			case 1: room_goto(RoomBoss1);break;
		}
		global.level = oCamera.stage;
		global.fase = oMainControl.level_map[# oCamera.stage-1, 0];
		}
	}
}