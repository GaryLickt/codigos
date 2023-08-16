/// @description Insert description here
// You can write your code in this editor
if oBossShadow.stage < 3 {
if bateu = false {
	audio_play_sound(choose(snd_ded,snd_ded2),1,0)
instance_destroy(other);
bateu = true;
alarm[1] = 60;
speed = 0;
path_speed = speed;
sprite_index = spr_carshadowBATEU;
alarm[2] = 120;
}
}

