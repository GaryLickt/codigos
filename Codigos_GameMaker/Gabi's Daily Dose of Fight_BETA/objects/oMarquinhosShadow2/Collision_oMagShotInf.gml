/// @description Insert description here
// You can write your code in this editor
if (bateu = false) and (counter < 5){
	counter += 1;
	audio_play_sound(choose(snd_ded,snd_ded2),1,0)
instance_destroy(other);
bateu = true;
alarm[1] = 180;
speed = 0;
path_speed = speed;
sprite_index = spr_carshadowBATEU;
if counter >= 5 {
alarm[2] = 240;
}else{
alarm[3] = 240;
alarm[2] = 320;
}
}

