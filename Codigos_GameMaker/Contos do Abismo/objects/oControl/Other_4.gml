/// @description Insert description here
// You can write your code in this editor
if (room_get_name(room) != "RoomMenu") and (room_get_name(room) != "RoomSelector") and (room_get_name(room) != "RoomStart"){
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
		}
	}
}
