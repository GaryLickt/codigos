/// @description Insert description here
// You can write your code in this editor
if dead = false {
if estado == scr_player_dash {

}else{
	dead = true;
	instance_destroy(other);
	estado = scr_player_boss2_ded;
	audio_play_sound(choose(snd_ded,snd_ded2,snd_ded3,snd_ded4,snd_ded5), 1,0)
}
}