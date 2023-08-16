/// @description Insert description here
// You can write your code in this editor
if estado != scr_player_dash {
if (dead == false) and (oControl.passou == false) {
dead = true;
estado = scr_player_ded;
if oMainConquistas.qual_desafio != "afogados" {
vspd -= 8;
}else{
vspd = 0;
alarm[4] = 15;
}
audio_play_sound(choose(snd_ded,snd_ded2,snd_ded3,snd_ded4,snd_ded5), 1,0)
}
}else{
instance_destroy(other);
audio_play_sound(choose(snd_dead2,snd_dead3),1,0)

caos += 1;

}