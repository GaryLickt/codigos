/// @description Insert description here
// You can write your code in this editor
instance_destroy(other);
instance_create_layer(x, y, "Instances", oBombCollision);
instance_destroy();
audio_play_sound(choose(snd_dead2,snd_dead3),1,0)