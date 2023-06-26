/// @description Insert description here
// You can write your code in this editor
if place_meeting(x,y,oMouseCollision){
	//Verifica se a proxima fase é o BOSS
	var nextboss = false;
	if variable_global_get("fase") = 5 {
	nextboss = true;
	}else{
	nextboss = false;
	}
	// Verifica se a fase atual JÁ é a do BOSS, caso seja, avança para o proximo mundo
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

if nextboss = false {
room_goto(Room1);
}else if nextboss = true {
switch(variable_global_get("level")){
case 1: room_goto(RoomBoss1);break;
}
}

audio_stop_all();
}