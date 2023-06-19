/// @description Insert description here
// You can write your code in this editor
if (image_xscale = 1) and (image_yscale = 1) {
instance_destroy(other);
instance_destroy();
audio_play_sound(choose(snd_dead2,snd_dead3),1,0)
}else if (image_xscale > 1) and (image_yscale > 1) {
image_xscale -= 0.5;
image_yscale -= 0.5;
instance_destroy(other);
audio_play_sound(choose(snd_dead2,snd_dead3),1,0)
}