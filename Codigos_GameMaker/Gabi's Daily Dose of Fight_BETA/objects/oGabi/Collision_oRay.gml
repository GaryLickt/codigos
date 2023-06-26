/// @description Insert description here
// You can write your code in this editor
if estado != scr_player_dash {
if (other.sprite_index == spr_rayoff) and ((dead == false) and (oControl.passou == false)) {
dead = true;
estado = scr_player_ded;
vspd -= 8;
audio_play_sound(choose(snd_ded,snd_ded2,snd_ded3,snd_ded4,snd_ded5), 1,0)
}
}