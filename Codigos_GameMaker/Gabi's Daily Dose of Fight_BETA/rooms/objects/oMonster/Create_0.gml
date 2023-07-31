/// @description Insert description here
// You can write your code in this editor
randomize();
image_index = irandom_range(0,2);

switch(image_index){
case 0: audio_play_sound(snd_uimedo,5,false);break;
case 1: audio_play_sound(snd_uimedo2,5,false);break;
case 2: audio_play_sound(snd_uimedo3,5,false);break;
}