// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function scr_player(){
sprite_index = spr_gabi;
	scr_player_passed()
var left, right, up, down, chao, dash, shoot, s1, s2, s3, s4;
left = keyboard_check(ord("A"));
right = keyboard_check(ord("D"));
up = keyboard_check_pressed(ord("W")) || keyboard_check_pressed(vk_space);
down = keyboard_check(ord("S"));
chao = place_meeting(x, y + 1, oChao);
dash = mouse_check_button_pressed(mb_right);
shoot = mouse_check_button_pressed(mb_left);
s1 = keyboard_check_pressed(ord("Z"));
s2 = keyboard_check_pressed(ord("X"));
s3 = keyboard_check_pressed(ord("C"));
s4 = keyboard_check_pressed(ord("V"));
var movex = right - left

vspd = vspd + grv;

if movex != 0 {
spd = 5;
}else{
spd = 0;
}
spd_dir = point_direction(x, y, x + movex, y);
hspd = lengthdir_x(spd,spd_dir);

if down {
grv = 0.6
}else{
grv = 0.3
}

if up and chao {
vspd -= 8;
if !audio_is_playing(snd_jump) {
audio_play_sound(choose(snd_jump,snd_jump3,snd_jump4,snd_jump5,snd_jump6,snd_jump7),1,0);
alarm[3] = 16.8;
}
}
if !chao {
sprite_index = spr_gabijump;
}

scr_player_collision();

if dash and (alarm[1] <= 0) {
alarm[0] = 20;
alarm[1] = 120;
dash_dir = point_direction(x, y, mouse_x, mouse_y);
estado = scr_player_dash;
audio_play_sound(choose(snd_dash1,snd_dash2,snd_dash3),1,0)
}

if shoot and (alarm[2] <= 0) and (dead == false) {
alarm[2] = 60;
instance_create_layer(x+30, y, "Instances", oCut);
}

if s1 and (skill1 <= 0) {
actvi1 = true;
alarm[3] = 120;
}

if actvi1 = true {
if irandom_range(0,10) < 5 {
var shot = instance_create_layer(x+10, y+irandom_range(-8, 8), "Instances", oMagShot);
shot.direction = point_direction(x, y, x + 1, y);
shot.image_angle = point_direction(x, y, x + 1, y);
shot.speed = 10;
}
}

}

function scr_player_run(){
	scr_player_passed()
var left, right, up, down, chao;
left = keyboard_check(ord("A"));
right = keyboard_check(ord("D"));
up = keyboard_check_pressed(ord("W")) || keyboard_check_pressed(vk_space);
down = keyboard_check(ord("S"));
chao = place_meeting(x, y + 1, oChaoParent);

var movex = right - left

vspd = vspd + grv;

cam_dir = floor(point_direction(x, y, mouse_x, mouse_y)/90)

switch(cam_dir){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}

if movex != 0 {
spd = 4;
}else{
spd = 0;
}
spd_dir = point_direction(x, y, x + movex, y);
hspd = lengthdir_x(spd,spd_dir);

if down {
grv = 0.5
}else{
grv = 0.2
}

if up and chao {
vspd -= 6;
}

var _dash = instance_create_layer(x, y, "Instances", oDash)
_dash.sprite_index = sprite_index


scr_player_collision();
}

	
function scr_player_dash(){
	scr_player_passed()
	spd = 10;
	hspd = lengthdir_x(dash_spd, dash_dir);
	vspd = lengthdir_y(dash_spd, dash_dir);
	
	scr_player_collision()
	
	var _dash = instance_create_layer(x, y, "Instances", oDash)
	_dash.sprite_index = sprite_index
}

function scr_player_collision(){
if place_meeting(x + hspd, y, oChaoParent) {
while(!place_meeting(x + sign(hspd), y, oChaoParent)){
x+=sign(hspd)
}
hspd = 0;
}
x+= hspd;

if place_meeting(x, y + vspd, oChaoParent) {
while(!place_meeting(x, y + sign(vspd), oChaoParent)){
y+=sign(vspd)
}
vspd = 0;
}
y+= vspd;
}

function scr_player_end_collision(){
x+= hspd;

if place_meeting(x, y + vspd, oChaoParent) {
while(!place_meeting(x, y + sign(vspd), oChaoParent)){
y+=sign(vspd)
}
vspd = 0;
}
y+= vspd;
}

function scr_player_dead_collision(){
var jumpower = 8;
x+= hspd;

if place_meeting(x, y + vspd, oChaoParent) {
while(!place_meeting(x, y + sign(vspd), oChaoParent)){
y+=sign(vspd)
}
if jumpower > 0 {
vspd -= jumpower;
jumpower -= 2;
}else{
vspd = 0;
}
}
y+= vspd;
}

function scr_player_dead(){
	sprite_index = spr_gabidead;
var chao = place_meeting(x, y + 1, oChaoParent);
spd = 4;
grv = 0.3;
spd_dir = point_direction(x, y, x + 1, y);
hspd = lengthdir_x(spd,spd_dir);
hspd -= 0.01;
vspd = vspd + grv;

if !chao {
angle -= 1;
}

scr_player_dead_collision()
}

function scr_player_passed(){
if oControl.passou == true {
estado = scr_player_end_anim;
}
}

function scr_player_end_anim(){
spd = 5;
grv = 0.3;
spd_dir = point_direction(x, y, x + 1, y);
hspd = lengthdir_x(spd,spd_dir);
vspd = vspd + grv;

scr_player_end_collision()
}