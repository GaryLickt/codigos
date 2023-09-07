// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function scr_player(){
var _movex = keyboard_check(vk_right) - keyboard_check(vk_left);
var _movey = keyboard_check(vk_down) - keyboard_check(vk_up);
var _flashlight = keyboard_check_pressed(ord("C"));
var _vision = keyboard_check_pressed(ord("V"));
var _agachamento = keyboard_check(ord("Z"));
var _run = keyboard_check(ord("X"));

if (_movex = 0) and (_movey = 0) {
spd = 0;
moving = false;
		if flash = false {
			sprite_index = spr_allan_still;
		}else{
			sprite_index = spr_allan_still_on;
		}
}else{
moving = true;
	if (!_agachamento and !_run) or (_agachamento and _run) {
spd = ispd;
		if flash = false {
			sprite_index = spr_allan_walk;
		}else{
			sprite_index = spr_allan_walk_on;
		}
	}
	if _agachamento and !_run{
spd = ispd-1;
		if flash = false {
			sprite_index = spr_allan_crouch;
		}else{
			sprite_index = spr_allan_crouch_on;
		}
	}
	if _run and !_agachamento{
spd = ispd+0.5;
		if flash = false {
			sprite_index = spr_allan_walk;
		}else{
			sprite_index = spr_allan_walk_on;
		}
	}
	
	
}

if _flashlight and (visi = false) and (alarm[5] <= 0) {
	flash = !flash;
	alarm[5] = 20;
	if flash = true {
		audio_play_sound(snd_lanternaON,1,false);
	}else{
		audio_play_sound(snd_lanternaOFF,1,false);
	}
}

if (tempo_maximo < 1) and (alarm[5] <= 0) {
visi = false;
alarm[5] = 300;
alarm[4] = 600;
tempo_maximo = 10.9;
}

if visi = true {
	if !place_meeting(x,y,oAntiVisionCollision){
tempo_maximo -= 0.015;
	}
image_alpha = 0.7;
}else{
image_alpha = 1;
}

if place_meeting(x,y,oAntiVisionCollision){
alarm[4] = 1;
}

if have_vision = true {
	if _vision and alarm[4] <= 0 {
	instance_create_layer(0,0,"Efeitos_top",oVisionON);
	if (visi = false) and (flash = true) {
	flash = false;
	alarm[4] = 60;
	audio_play_sound(snd_usafragmento,1,false);
	}

	if (visi = true) and tempo_maximo >= 1 {
	var temp = floor(tempo_maximo);
	switch(temp) {
		case 10: alarm[4] = 60;break;
		case 9: alarm[4] = 60;break;
		case 8: alarm[4] = 120;break;
		case 7: alarm[4] = 180;break;
		case 6: alarm[4] = 240;break;
		case 5: alarm[4] = 300;break;
		case 4: alarm[4] = 360;break;
		case 3: alarm[4] = 420;break;
		case 2: alarm[4] = 480;break;
		case 1: alarm[4] = 540;break;
	
	}
	tempo_maximo = 10.9;
	flash = true;
	audio_play_sound(snd_desligafragmento,1,false);
	}
	visi = !visi;
	}
}



if _agachamento {
crouch = true;
}else{
crouch = false;
}


if flash and !instance_exists(oFlashBarrier) {
instance_create_depth(x, y, depth, oFlashBarrier);
}
if !flash and instance_exists(oFlashBarrier) {
instance_destroy(oFlashBarrier);
}

spd_dir = point_direction(x, y, x + _movex, y + _movey);
if _movex != 0 {
dir_a = spd_dir/90;
}
switch(floor(dir_a)){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}

hspd = lengthdir_x(spd, spd_dir);
vspd = lengthdir_y(spd, spd_dir);

scr_collision();
}


function scr_collision(){
if place_meeting(x + hspd, y, oBarrierParent) {
	while(!place_meeting(x + sign(hspd), y, oBarrierParent)){
	x+= sign(hspd);
	}
hspd = 0;
}
x+=hspd;

if place_meeting(x, y + vspd, oBarrierParent) {
	while(!place_meeting(x, y + sign(vspd), oBarrierParent)){
	y+= sign(vspd);
	}
vspd = 0;
}
y+=vspd;
}