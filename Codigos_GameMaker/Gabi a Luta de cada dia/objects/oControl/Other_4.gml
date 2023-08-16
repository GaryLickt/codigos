/// @description Insert description here
// You can write your code in this editor
	if room_get_name(room) = "Room1" {
		correndo = true;
		if oMainConquistas.desafio_on = false {
			if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
				if !audio_is_playing(snd_factory){
					audio_play_sound(snd_factory, 1, true)
				}
			}
		}else{
			if oMainConquistas.qual_desafio = "distorcido" {
			alarm[5] = 60;
			}
		}
	}

if room_get_name(room) = "RoomBoss1" {
	if !audio_is_playing(snd_factoryboss){
		audio_play_sound(snd_factoryboss, 1, true)
	}
	total = oBossMarco.hp + 4;
	ilife = total;
	maxlife = total + 75;
}

if room_get_name(room) = "RoomBoss2" {
	total = (oGabiBoss2.hp*25) + 4;
	ilife = total;
	maxlife = total;
	
	total2 = (oBossShadow.hp) + 4;
	ilife2 = total2;
	maxlife2 = total2;
}

if room_get_name(room) = "EasterEgg" {
alarm[3] = 10 * 60;
}
if room_get_name(room) = "Easter2" {
	switch(oMonster.image_index){
case 0: audio_play_sound(snd_uimedo,5,false);break;
case 1: audio_play_sound(snd_uimedo2,5,false);break;
case 2: audio_play_sound(snd_uimedo3,5,false);break;
}
alarm[4] = 10 * 60;
}