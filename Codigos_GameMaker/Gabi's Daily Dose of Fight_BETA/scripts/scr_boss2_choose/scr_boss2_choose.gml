// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function scr_boss2_choose(){
	scr_boss2_checkstage();
pre_istagio = choose(scr_boss2_wait,scr_boss2_wait,scr_boss2_wait,scr_boss2_move,scr_boss2_wait);

if pre_istagio = scr_boss2_move {
dest_x = irandom_range(0,room_width);
dest_y = irandom_range(0,room_height);

spd_dir = point_direction(x,y,dest_x,dest_y);

hspd = lengthdir_x(spd,spd_dir);
vspd = lengthdir_y(spd,spd_dir);
alarm[0] = 120;
istagio = scr_boss2_move;
}else if pre_istagio = scr_boss2_wait {
alarm[0] = 60;
kip = choose(oBossShadowBall,oBossShadowRoundBall);
istagio = scr_boss2_wait;
chanc = irandom_range(0,100);
}
}
	
function scr_boss2_move(){
	scr_boss2_checkstage();
sprite_index = spr_nathanbossmove;
if instance_number(oBossShadowRicochet) < 5{
	if random_range(0,100) <= 5 {
	var a = instance_create_layer(x,y,"Instances",oBossShadowRicochet);
	a.speed = 4;
	a.direction = irandom_range(0,360);
	}
}

if point_distance(oGabiBoss2.x,oGabiBoss2.y, oBossShadow.x, oBossShadow.y) > 200 {
		var dir = point_direction(x,y,dest_x,dest_y);
		var b = floor(dir/90);
		
			switch(b){
			case 0: image_xscale = 1;break;
			case 1: image_xscale = -1;break;
			case 2: image_xscale = -1;break;
			case 3: image_xscale = 1;break;
			} 
		
		}else{
		var dir = point_direction(x,y,oGabiBoss2.x,oGabiBoss2.y);
		var b = floor(dir/90);
		
			switch(b){
			case 0: image_xscale = 1;break;
			case 1: image_xscale = -1;break;
			case 2: image_xscale = -1;break;
			case 3: image_xscale = 1;break;
			} 
		}

scr_player_collision();
}

function scr_boss2_wait(){
	scr_boss2_checkstage();
sprite_index = spr_nathanboss;

switch(prio){
case 1: scr_boss2_attack1();break;
case 2: scr_boss2_attack2();break;
case 3: scr_boss2_attack3();break;
}
}

function scr_boss2_attack1(){
	if chanc <= 50 {
		var vezes = irandom_range(3,6);
		if (alarm[1] <= 0) and (vezes > 0){
			if irandom_range(0,100) <= 5 {
		alarm[1] = 15;
			}
		vezes--;
		}
		if vezes <= 0 {
			if prio < 3 {
			prio = choose(prio+1,1);
			}else{
			prio = 1;
			}
		}
	}else{
		if (alarm[1] <= 0){
			if irandom_range(0,100) <= 5 {
			alarm[1] = 15;
			}
		}
		if prio < 3 {
		prio = choose(prio+1,1);
		}else{
		prio = 1;
		}
	}
}

function scr_boss2_attack2(){
	if !instance_exists(oBossShadowGUN){
		var _s = instance_create_depth(x,y,depth-1,oBossShadowGUN);
		_s.image_angle = point_direction(x,y,oGabiBoss2.x,oGabiBoss2.y);
	
		if prio < 3 {
			prio = choose(prio+1,1);
		}else{
			prio = 1;
		}
	}else{
		if prio < 3 {
			prio = choose(prio+1,1);
		}else{
			prio = 1;
		}
	}
}

function scr_boss2_attack3(){
	if irandom_range(0,100) <= 5 {
var _x = irandom_range(0,room_width);

var _bob = instance_create_layer(_x,0,"Instances",oBossShadowHydra);
_bob.speed = 3;
_bob.direction = point_direction(x,y,x,y+1);
_bob.image_angle = point_direction(x,y,x,y+1);
	}
if prio < 3 {
			prio = choose(prio+1,2);
		}else{
			prio = choose(2,1);
		}
}

function scr_boss2_checkstage(){
if (hp > 20) and (hp <= 299){
stage = 2;
}
if (hp <=20) {
stage = 3;
alarm[3] = 300;
istagio = scr_boss2_transition;
}
}

function scr_boss2_transition(){
sprite_index = spr_nathanbossbug;
}
	
// DRACO BOSS

function scr_boss2_phase2(){
pre_istagio = choose(scr_boss2_phase2_wait,scr_boss2_phase2_wait,scr_boss2_phase2_wait,scr_boss2_phase2_move,scr_boss2_phase2_wait);

if pre_istagio = scr_boss2_phase2_move {
dest_x = irandom_range(0,room_width);
dest_y = irandom_range(0,room_height);

spd_dir = point_direction(x,y,dest_x,dest_y);

hspd = lengthdir_x(spd,spd_dir);
vspd = lengthdir_y(spd,spd_dir);
alarm[0] = 120;
istagio = scr_boss2_phase2_move;
}else if pre_istagio = scr_boss2_phase2_wait {
alarm[0] = 60;
kip = choose(oBossShadowBall,oBossShadowRoundBall);
istagio = scr_boss2_phase2_wait;
chanc = irandom_range(0,100);
}
}
	
function scr_boss2_phase2_move(){
if point_distance(oGabiBoss2.x,oGabiBoss2.y, oBossShadow.x, oBossShadow.y) > 200 {
		var dir = point_direction(x,y,dest_x,dest_y);
		var b = floor(dir/90);
		
			switch(b){
			case 0: image_xscale = 1;break;
			case 1: image_xscale = -1;break;
			case 2: image_xscale = -1;break;
			case 3: image_xscale = 1;break;
			} 
		
		}else{
		var dir = point_direction(x,y,oGabiBoss2.x,oGabiBoss2.y);
		var b = floor(dir/90);
		
			switch(b){
			case 0: image_xscale = 1;break;
			case 1: image_xscale = -1;break;
			case 2: image_xscale = -1;break;
			case 3: image_xscale = 1;break;
			} 
		}

scr_player_collision();
}

function scr_boss2_phase2_wait(){

switch(prio){
case 1: scr_boss2_phase2_attack1();break;
case 2: scr_boss2_phase2_attack2();break;
case 3: scr_boss2_attack3();break;
}
}
	
function scr_boss2_phase2_attack1(){
	var _a = instance_create_layer(x,y,"Instances",oBossDracoRicoBall);
var _b = instance_create_layer(x,y,"Instances",oBossDracoRicoBall);
var _c = instance_create_layer(x,y,"Instances",oBossDracoRicoBall);
var _d = instance_create_layer(x,y,"Instances",oBossDracoRicoBall);

_a.speed = 6;
_b.speed = 6;
_c.speed = 6;
_d.speed = 6;

_a.direction = 0;
_b.direction = 90;
_c.direction = 180;
_d.direction = 270;

		if prio < 3 {
			prio = choose(prio+1,1);
		}else{
			prio = 1;
		}
alarm[0] = 1;
}

function scr_boss2_phase2_attack2(){
	if !instance_exists(oBossShadowGUN){
		var _s = instance_create_depth(x,y,depth-1,oBossShadowGUN);
		_s.image_angle = point_direction(x,y,oGabiBoss2.x,oGabiBoss2.y);
	
		if prio < 3 {
			prio = choose(prio+1,1);
		}else{
			prio = 1;
		}
	}else{
		if prio < 3 {
			prio = choose(prio+1,1);
		}else{
			prio = 1;
		}
	}
}