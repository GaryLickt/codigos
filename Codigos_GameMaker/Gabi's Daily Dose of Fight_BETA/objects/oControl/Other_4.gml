/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) != "RoomBoss1" {
	if room_get_name(room) = "Room1" {
		correndo = true;
		if !audio_is_playing(snd_factory){
			audio_play_sound(snd_factory, 1, true)
		}
	}
}else{
	if !audio_is_playing(snd_factoryboss){
		audio_play_sound(snd_factoryboss, 1, true)
	}
	total = oBossMarco.hp + 4;
	ilife = total;
	maxlife = total + 75;
}
if room_get_name(room) = "EasterEgg" {
alarm[3] = 10 * 60;
}
if room_get_name(room) = "Easter2" {
alarm[4] = 10 * 60;
}