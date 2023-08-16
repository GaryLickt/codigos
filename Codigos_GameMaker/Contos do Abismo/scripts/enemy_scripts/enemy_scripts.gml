// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
#region TEDDY
function scr_teddy_check(){
var isVisible = !collision_line(x, y, oAllan.x, oAllan.y, oBarrier, false, true);
if ((distance_to_object(oAllan) < 200) and oAllan.visi = false) and isVisible {
alarm[1] = 1;
oAllan.detect = true;
puto = true;
state = scr_teddy_chase;
}
}

function scr_teddy_choose(){
	switch(visao){
		case true: sprite_index = spr_tsenti_still;break;
		case false: sprite_index = spr_teddy_still;break;
	}
	puto = false;
scr_teddy_check();
pos_state = choose(scr_teddy_still, scr_teddy_walk);

if pos_state = scr_teddy_walk {
dest_x = irandom_range(0, room_width);
dest_y = irandom_range(0, room_height);
spd_dir = point_direction(x, y, dest_x, dest_y);
hspd = lengthdir_x(spd, spd_dir);
vspd = lengthdir_y(spd, spd_dir);
alarm[0] = 60;
state = scr_teddy_walk;
}else if pos_state = scr_teddy_still {
alarm[0] = 60;
state = scr_teddy_still;
}
}
	
function scr_teddy_still(){
	puto = true;
	scr_teddy_ambient_sound()
	switch(visao){
		case true: sprite_index = spr_tsenti_still;break;
		case false: sprite_index = spr_teddy_still;break;
	}
scr_teddy_check();
}

function scr_teddy_walk(){
	scr_teddy_ambient_sound()
	switch(visao){
		case true: sprite_index = spr_tsenti_walk;break;
		case false: sprite_index = spr_teddy_walk;break;
	}
scr_teddy_check();
	scr_collision();
dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}
}
	
function scr_teddy_chase(){
	var isVisible = !collision_line(x, y, oAllan.x, oAllan.y, oBarrier, false, true);
	sprite_index = spr_teddy_chase;
dest_x = oAllan.x;
dest_y = oAllan.y;
spd_dir = point_direction(x, y, dest_x, dest_y);

dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}

	
if (distance_to_object(oAllan) > 300) or (oAllan.visi = true) {
state = scr_teddy_still;
oAllan.detect = false;
}
	
if (place_meeting(x, y, oFlashBarrier)) and (isVisible){
state = scr_teddy_chock;
oAllan.detect = false;
}
}

function scr_teddy_chock(){
	switch(visao){
		case true: sprite_index = spr_tsenti_still;break;
		case false: sprite_index = spr_teddy_still;break;
	}
	puto = false;
if place_meeting(x, y, oFlashBarrier) {
alarm[0] = 240;
}
}

#endregion

#region SASHA
function scr_sasha_check(){
	var isVisible = !collision_line(x, y, oAllan.x, oAllan.y, oBarrier, false, true);
	if (distance_to_object(oAllan) < 240) and oAllan.visi = false {
		if ((oAllan.crouch = false) and (oAllan.moving = true)) {
			if isVisible {
				alarm[1] = 1;
				oAllan.detect = true;
				puto = true;
				state = scr_sasha_chase;
			}
		}
	}
}

function scr_sasha_choose(){
	switch(oAllan.visi){
		case true: sprite_index = spr_ssenti_still;break;
		case false: sprite_index = spr_sasha_still;break;
	}
	puto = false;
	scr_sasha_check();
pos_state = choose(scr_sasha_still, scr_sasha_walk);

if pos_state = scr_sasha_walk {
dest_x = irandom_range(0, room_width);
dest_y = irandom_range(0, room_height);
spd_dir = point_direction(x, y, dest_x, dest_y);
hspd = lengthdir_x(spd, spd_dir);
vspd = lengthdir_y(spd, spd_dir);
alarm[0] = 60;
state = scr_sasha_walk;
}else if pos_state = scr_sasha_still {
alarm[0] = 60;
state = scr_sasha_still;
}
}

function scr_sasha_still(){
	puto = true;
	switch(oAllan.visi){
		case true: sprite_index = spr_ssenti_still;break;
		case false: sprite_index = spr_sasha_still;break;
	}
scr_sasha_check();
}

function scr_sasha_walk(){
	switch(oAllan.visi){
		case true: sprite_index = spr_ssenti_walk;break;
		case false: sprite_index = spr_sasha_walk;break;
	}
	scr_sasha_check();
scr_collision();

dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}
}

function scr_sasha_chase(){
	if (visao = false) {
		sprite_index = spr_sasha_chase;
		dest_x = oAllan.x;
		dest_y = oAllan.y;
		spd_dir = point_direction(x, y, dest_x, dest_y);

		dir_a = floor(spd_dir/90);
		switch(dir_a){
			case 0: image_xscale = 1;break;
			case 1: image_xscale = -1;break;
			case 2: image_xscale = -1;break;
			case 3: image_xscale = 1;break;
		}

}else if (visao) {
		stage = scr_sasha_choose;
		oAllan.detect = false;
	}

}

#endregion

#region BANNI
function scr_banni_check(){
var isVisible = !collision_line(x, y, oAllan.x, oAllan.y, oBarrier, false, true);
if ((distance_to_object(oAllan) < 200) and oAllan.visi = false) and (oAllan.flash = true) and isVisible {
alarm[1] = 1;
oAllan.detect = true;
puto = true;
state = scr_banni_chase;
}
}

function scr_banni_choose(){
	sprite_index = spr_banni_still;
	puto = true;
scr_banni_check();
pos_state = choose(scr_banni_still, scr_banni_walk);

if pos_state = scr_banni_walk {
dest_x = irandom_range(0, room_width);
dest_y = irandom_range(0, room_height);
spd_dir = point_direction(x, y, dest_x, dest_y);
hspd = lengthdir_x(spd, spd_dir);
vspd = lengthdir_y(spd, spd_dir);
alarm[0] = 60;
state = scr_banni_walk;
}else if pos_state = scr_banni_still {
state = scr_banni_still;
alarm[0] = 60;
}
}
	
function scr_banni_still(){
	puto = true;
	sprite_index = spr_banni_still;
scr_banni_check();
}

function scr_banni_walk(){
	sprite_index = spr_banni_walk;
scr_banni_check();
scr_collision();

dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}
}

function scr_banni_chase(){
sprite_index = spr_banni_chase;

dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}

if ((distance_to_object(oAllan) > 200) and (oAllan.flash = false)) or (oAllan.visi = true) {
	state = scr_banni_choose;
	oAllan.detect = false;
}
}

#endregion

#region FELIX
function scr_felix_check(){
var isVisible = !collision_line(x, y, oAllan.x, oAllan.y, oBarrier, false, true);
if ((distance_to_object(oAllan) < 150) and oAllan.visi = false) and (oAllan.moving = true) and isVisible {
alarm[1] = 1;
state = scr_felix_chase;
puto = true;
oAllan.detect = true;
}
}

function scr_felix_choose(){
	puto = true;
	sprite_index = spr_felix_still;
	scr_felix_check();
pos_state = choose(scr_felix_still, scr_felix_walk);

if pos_state = scr_felix_walk {
dest_x = irandom_range(0, room_width);
dest_y = irandom_range(0, room_height);
spd_dir = point_direction(x, y, dest_x, dest_y);
hspd = lengthdir_x(spd, spd_dir);
vspd = lengthdir_y(spd, spd_dir);
alarm[0] = 60;
state = scr_felix_walk;
}else if pos_state = scr_felix_still {
alarm[0] = 30;
state = scr_felix_still;
}
}

function scr_felix_chase(){
	sprite_index = spr_felix_chase;
	spd_dir = point_direction(x, y, oAllan.x, oAllan.y);
	dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}

if oAllan.visi = true {
stage = scr_felix_still;
oAllan.detect = false;
}
}
	
function scr_felix_still(){
	puto = true;
	sprite_index = spr_felix_still;
scr_felix_check();
}

function scr_felix_walk(){
	sprite_index = spr_felix_still;
	scr_felix_check();
scr_collision();

dir_a = floor(spd_dir/90);
switch(dir_a){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}
}

#endregion


function scr_teddy_ambient_sound(){
if random_range(0,100) <= 15 {
	if ((audio_is_playing(snd_ambient1)) or (audio_is_playing(snd_ambient2)) or (audio_is_playing(snd_ambient3))) = false {
	audio_play_sound_at(choose(snd_ambient1,snd_ambient2,snd_ambient3),x,y,0,100,300,1,false,1);
	}
}
}