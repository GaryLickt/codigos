/// @description Insert description here
// You can write your code in this editor
if other.stage != 3 {
other.hp -= 1;
instance_destroy();
audio_play_sound(choose(snd_dead2,snd_dead3),1,0);
}
