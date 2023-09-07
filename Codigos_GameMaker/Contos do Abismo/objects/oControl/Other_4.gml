/// @description Insert description here
// You can write your code in this editor
if (room_get_name(room) != "RoomMenu") and (room_get_name(room) != "RoomSelector") and (room_get_name(room) != "RoomStart") and (room_get_name(room) != "RoomAviso"){
	audio_stop_sound(snd_menusound);
	if room_get_name(room) = "RoomOver" {
		switch(kill){
			case 1: audio_play_sound(snd_jumpscare,2,0);audio_play_sound(snd_sjumpscare,1,0);break;
			case 3: audio_play_sound(snd_jumpscare,2,0);audio_play_sound(snd_sjumpscare,1,0);break;
			case 2: audio_play_sound(snd_jumpscare,2,0);audio_play_sound(snd_sjumpscare,1,0);break;
			case 4: audio_play_sound(snd_jumpscare,2,0);audio_play_sound(snd_sjumpscare,1,0);break;
		}

	audio_play_sound(snd_h1clock, 0, true);
	}else{
		if history = 1 {
			if !(audio_is_playing(snd_h1ambient)) {
				audio_play_sound(snd_h1ambient, 5, true);
			}
			if !(audio_is_playing(snd_h1clock)) {
				audio_play_sound(snd_h1clock, 5, true);
			}
		if (room_get_name(room) = "Room3") and (cena1 = true) {
		instance_create_layer(175,32,"Instances",oManequin);
		instance_create_layer(205,32,"Instances",oManequin);
		instance_create_layer(235,32,"Instances",oManequin);
		}
		if (room_get_name(room) = "Room2") and (cena1 = true) {
		instance_create_layer(814,40,"Instances",oManequin);
		instance_create_layer(844,40,"Instances",oManequin);
		instance_create_layer(874,40,"Instances",oManequin);
		}
		}
	}
}else{
	if room_get_name(room) = "RoomMenu" {
		audio_play_sound(snd_menusound,1,0);
	}
}
