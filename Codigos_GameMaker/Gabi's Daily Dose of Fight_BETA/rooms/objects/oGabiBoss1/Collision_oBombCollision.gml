/// @description Insert description here
// You can write your code in this editor
if estado != scr_playerboss1_vitoria {
	if dead = false {
		if estado == scr_player_dash {

		}else{
			dead = true;
			instance_destroy(other);
			vspd-= 8;
			estado = scr_player_boss_ded;
			audio_play_sound(choose(snd_ded,snd_ded2,snd_ded3,snd_ded4,snd_ded5), 1,0)
		}
	}
}