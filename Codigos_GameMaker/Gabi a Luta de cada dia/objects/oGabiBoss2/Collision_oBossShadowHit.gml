/// @description Insert description here
// You can write your code in this editor
if (tomardano = true) and (hp > 1) {
	estado = scr_player_boss2_hit;
	var _dir = point_direction(other.x,other.y,x,y);
	empurra_dir = _dir;
audio_play_sound(choose(snd_ded,snd_ded2,snd_ded3,snd_ded4,snd_ded5),1,0);
instance_destroy(other);
hp--;
tomardano = false;
alarm[4] = 10;
alarm[5] = 180;
}else if (tomardano = true) and (hp = 1){
estado = scr_player_boss2_ded;
hp--;
audio_play_sound(choose(snd_ded,snd_ded2,snd_ded3,snd_ded4,snd_ded5),1,0);
instance_destroy(other);
dead_yaxis = y;
y-= 5;
}

