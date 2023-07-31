/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "RoomMenu" {
if oDoly.sprite_index = spr_doly {
	if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
		if !audio_is_playing(snd_menuambient){
			audio_play_sound(snd_menuambient,1,true);
		}
	}
}else if oDoly.sprite_index = spr_curseddoly {
	if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
		if !audio_is_playing(yaygnosunem_dns){
			audio_play_sound(yaygnosunem_dns,1,true);
		}
	}
}
}else{
	if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
		if !audio_is_playing(snd_menuambient){
			audio_play_sound(snd_menuambient,1,true);
		}
	}
}