// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
#region Fases Normais
	function scr_player(){
	sprite_index = spr_gabi;
		scr_player_passed()
	
	#region Variaveis
	var left, right, up, down, chao, dash, shoot, s1, s2, s3, s4;
	left = keyboard_check(ord("A"));
	right = keyboard_check(ord("D"));
	up = 0;
	down = 0;
	if yscale > 0 {
		up = keyboard_check_pressed(ord("W")) || keyboard_check_pressed(vk_space);
		down = keyboard_check(ord("S"));
	}else if yscale < 0 {
		up = keyboard_check_pressed(ord("S"));
		down = keyboard_check(ord("W")) || keyboard_check_pressed(vk_space);
	}
	chao = place_meeting(x, y + 1, oBarreiraParent);
	dash = mouse_check_button_pressed(mb_right);
	shoot = mouse_check_button_pressed(mb_left);
	s1 = keyboard_check_pressed(ord("1")) || keyboard_check_pressed(ord("Z"));
	s2 = keyboard_check_pressed(ord("2")) || keyboard_check_pressed(ord("X"));
	s3 = keyboard_check_pressed(ord("3")) || keyboard_check_pressed(ord("C"));
	s4 = keyboard_check_pressed(ord("4")) || keyboard_check_pressed(ord("V"));
	var movex = 0;
	if xscale > 0 {
		movex = right - left;
	}else if xscale < 0 {
		movex = left - right;
	}

	vspd = vspd + grv;

	#endregion

	#region Codigo Main()
	if movex != 0 {
		if movex = 1 {
			if oMainConquistas.qual_desafio != "afogados" {
			image_speed = 1.2;
			spd = 5.2;
			}else{
			image_speed = 0.6;
			spd = 2.6;
			}
		}else if movex = -1 {
			if oMainConquistas.qual_desafio != "afogados" {
			image_speed = 0.8;
			spd = 4.8;
			}else{
			image_speed = 0.4;
			spd = 2.4;
			}
		}
	}else{
		spd = 0;
		image_speed = 1;
	}
	spd_dir = point_direction(x, y, x + movex, y);
	hspd = lengthdir_x(spd,spd_dir);

	if oMainConquistas.qual_desafio != "sempulo" {
		if (down and (yscale > 0)) or (up and (yscale < 0)) {
			if oMainConquistas.qual_desafio != "afogados" {
			grv = 0.8
			}else{
			grv = 0.4
			}
		}else{
			if oMainConquistas.qual_desafio != "afogados" {
			grv = 0.4
			}else{
			grv = 0.2
			}
		}

		if (up and chao and (yscale > 0)) or (down and chao and (yscale < 0)) {
			if oMainConquistas.qual_desafio != "afogados" {
			vspd -= 10;
			}else{
				vspd -= 7;
			}
		if !audio_is_playing(snd_jump) {
		audio_play_sound(choose(snd_jump,snd_jump3,snd_jump4,snd_jump5,snd_jump6,snd_jump7),1,0);
		}
		}
		if !chao {
			sprite_index = spr_gabijump;
		}
	}
	
	if instance_exists(oCutDash){
	sprite_index = spr_gabibate;
	}
	
	if instance_exists(oCut){
		if oMainConquistas.qual_desafio != "afogados"{
	spd = 5.4;
		}else{
	spd = 2.7;
		}
	vspd = 0;
	spd_dir = point_direction(x, y, x + 1, y);
	hspd = lengthdir_x(spd,spd_dir);
	sprite_index = spr_gabibate;
	}
	if instance_exists(oCutback){
		if oMainConquistas.qual_desafio != "afogados"{
	spd = 4.4;
		}else{
	spd = 2.2;
		}
	vspd = 0;
	spd_dir = point_direction(x, y, x + 1, y);
	hspd = lengthdir_x(spd,spd_dir);
	}

	scr_player_collision();

	if oMainConquistas.qual_desafio != "sempulo" {
		if dash and (alarm[1] <= 0) {
			alarm[0] = 20;
			alarm[1] = 120;
			dash_dir = point_direction(x, y, mouse_x, mouse_y);
			estado = scr_player_dash;
			audio_play_sound(choose(snd_dash1,snd_dash2,snd_dash3),1,0)
		}
	}

	if shoot and (alarm[2] <= 0) and (dead == false) {
	alarm[2] = 45;
	instance_create_depth(x+30, y, depth-1, oCut);
	}
	#endregion

	#region Habilidades
	if s1 and (skill1 <= 0) and (global.sk1 = true) {
	actvi1 = true;
	alarm[3] = 180;
	}

	if s2 and (skill2 <= 0) and (!instance_exists(oWheel)) and (global.sk2 = true) {
	actvi2 = true;
	}

	if actvi1 = true {
		if irandom_range(0,10) < 5 {
			if oMainConquistas.qual_desafio != "sempulo" {
			var shot = instance_create_layer(x+30, y+3, "Instances", oMagShot);
			shot.direction = point_direction(x, y, x + 1, y+random_range(-0.1, 0.1));
			shot.image_angle = point_direction(x, y, x + 1, y+random_range(-0.1, 0.1));
				if oMainConquistas.qual_desafio != "afogados"{
			shot.speed = 10;
				}else{
			shot.speed = 5;
				}
			
			}else{
			var shot = instance_create_layer(x+30, y+3, "Instances", oMagShot);
			shot.direction = point_direction(x, y, x + 1, y+random_range(-0.1, 0.1));
			shot.image_angle = point_direction(x, y, x + 1, y+random_range(-0.1, 0.1));
			shot.speed = 10;
			}
		}
		if !chao {
			sprite_index = spr_gabijumpshot;
		}else{
			sprite_index = spr_gabishot;
		}
	}
	if actvi2 = true {
	var bumer = instance_create_layer(x + 5, y+35, "Instances", oWheel);
	if oMainConquistas.qual_desafio != "afogados"{
	bumer.speed = 4;
	}else{
	bumer.speed = 2;
	}
	bumer.direction = 0
	actvi2 = false;
	}

	#endregion

	}

	function scr_player_run(){
		
	}

	function scr_player_dash(){
		scr_player_passed()
		if oMainConquistas.qual_desafio != "afogados"{
		spd = 10;
		}else{
		spd = 5;
		}
		sprite_index = spr_gabidash;
		hspd = lengthdir_x(dash_spd, dash_dir);
		vspd = lengthdir_y(dash_spd, dash_dir);
	
		scr_player_collision()
	
		var _dash = instance_create_layer(x, y, "Instances", oDash)
		_dash.sprite_index = sprite_index;
		_dash.spd = 0.02;
		_dash.image_alpha = 0.6;
	}

	function scr_player_collision(){
	if place_meeting(x + hspd, y, oBarreiraParent) {
	while(!place_meeting(x + sign(hspd), y, oBarreiraParent)){
	x+=sign(hspd);
	}
	hspd = 0;
	}
	x+= hspd;

	if place_meeting(x, y + vspd, oBarreiraParent) {
	while(!place_meeting(x, y + sign(vspd), oBarreiraParent)){
	y+=sign(vspd);
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

	function scr_player_ded(){
		if oMainConquistas.qual_desafio != "afogados"{
		vspd = vspd + grv;
		sprite_index = spr_gabijump;

			x+= (image_xscale)*4;
		y+= vspd;
	
		depth = -(y*10);
		
		angle += (image_xscale)*4;
		}else{
		sprite_index = spr_gabijump;
		var pxXVII = (image_xscale)*1.5;
		if vspd > 0 {
		pxXVII -= 0.05;
		}
			x+= pxXVII;
		y+= vspd;
	
		depth = -(y*10);
		
		angle += (image_xscale)*2;
		}
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

		sprite_index = spr_gabiend;
		scr_player_end_collision()
	}
#endregion

#region BOSS KATÔTA
	function scr_player_boss(){
	sprite_index = spr_gabi;
		scr_player_passed()
	
	#region Variaveis
	var left, right, up, down, chao, chaoEx, dash, shoot, s1, s2, s3, s4;
	left = keyboard_check(ord("A"));
	right = keyboard_check(ord("D"));
	up = keyboard_check_pressed(ord("W")) || keyboard_check_pressed(vk_space);
	down = keyboard_check(ord("S"));
	chao = place_meeting(x, y + 1, oChao);
	chaoEx = place_meeting(x, y + 1, oBarreiraParent);
	dash = mouse_check_button_pressed(mb_right);
	shoot = mouse_check_button_pressed(mb_left);
	s1 = keyboard_check_pressed(ord("1")) || keyboard_check_pressed(ord("Z"));
	s2 = keyboard_check_pressed(ord("2")) || keyboard_check_pressed(ord("X"));
	s3 = keyboard_check_pressed(ord("3")) || keyboard_check_pressed(ord("C"));
	s4 = keyboard_check_pressed(ord("4")) || keyboard_check_pressed(ord("V"));
	var movex = right - left

	vspd = vspd + grv;

	#endregion

	#region Codigo Main()
	
	if oBossMarco.hp > 0 {
		if movex != 0 {
		spd = 5;
		}else{
		spd = 0;
		sprite_index = spr_gabistill;
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
		}
		}
		if !chaoEx {
		sprite_index = spr_gabijump;
		}
	
		scr_player_direction();
	
		scr_player_collision();

		if dash and (alarm[1] <= 0) {
		alarm[0] = 20;
		alarm[1] = 120;
		dash_dir = point_direction(x, y, mouse_x, mouse_y);
		estado = scr_player_dash;
		audio_play_sound(choose(snd_dash1,snd_dash2,snd_dash3),1,0)
		}

		if shoot and (alarm[2] <= 0) and (dead == false) {
		alarm[2] = 15;
		var pow = instance_create_layer(x, y, "Instances", oMagShotInf);
		pow.direction = point_direction(x, y, mouse_x, mouse_y+random_range(-0.5, 0.5));
		pow.image_angle = point_direction(x, y, mouse_x, mouse_y+random_range(-0.5, 0.5));
		pow.speed = 10;
	
		var pow1 = instance_create_layer(x, y, "Instances", oMagShotInf);
		pow1.direction = point_direction(x, y, mouse_x+25, mouse_y+random_range(-0.5, 0.5));
		pow1.image_angle = point_direction(x, y, mouse_x+25, mouse_y+random_range(-0.5, 0.5));
		pow1.speed = 10;
	
		var pow2 = instance_create_layer(x, y, "Instances", oMagShotInf);
		pow2.direction = point_direction(x, y, mouse_x-25, mouse_y+random_range(-0.5, 0.5));
		pow2.image_angle = point_direction(x, y, mouse_x-25, mouse_y+random_range(-0.5, 0.5));
		pow2.speed = 10;
		}
		#endregion

		#region Habilidades
		if s1 and (skill1 <= 0) {
		actvi1 = true;
		alarm[3] = 60;
		}

		if s2 and (skill2 <= 0) and (!instance_exists(oWheel)) {
		actvi2 = true;
		}
		if actvi1 = true {
			if irandom_range(0,10) < 5 {
				var shot = instance_create_layer(x+10, y+irandom_range(-8, 8), "Instances", oMagShotInf);
				shot.direction = point_direction(x, y, mouse_x, mouse_y+random_range(-2, 2));
				shot.image_angle = point_direction(x, y, mouse_x, mouse_y+random_range(-2, 2));
				shot.speed = 10;
			}
		}
		if actvi2 = true {
		var bumer = instance_create_layer(x + 5, y+30, "Instances", oWheel);
		bumer.speed = 4;
		bumer.direction = point_direction(x, y, mouse_x, mouse_y);
		actvi2 = false;
		}

		#endregion
	}
	}
		
	function scr_playerboss1_vitoria(){
		var chao = place_meeting(x, y + 1, oChao);
		var chaoEx = place_meeting(x, y + 1, oBarreiraParent);
		
		if !chaoEx {
			sprite_index = spr_gabijump;
		}else{
			sprite_index = spr_gabistill;
		}
		vspd = vspd + grv;
	
		if place_meeting(x, y + vspd, oBarreiraParent) {
			while(!place_meeting(x, y + sign(vspd), oBarreiraParent)){
				y+=sign(vspd);
			}
			vspd = 0;
		}
		y+= vspd;
	}

	function scr_player_direction(){
	
		if (x < mouse_x)        // check if the player is left of the mouse
		{
		image_xscale = 1; // set the sprite to the one facing left
		}
		else
		{
		image_xscale = -1; // set the sprite to the one facing right
		}

	}

	function scr_player_boss_ded(){
		vspd = vspd + grv;

			x+= (image_xscale)*4;
		y+= vspd;
	
		depth = -(y*10);
		
		angle += (image_xscale)*4;
	}
#endregion

#region BOSS NATHAN
	function scr_player_boss2(){
		spd = 5;
		sprite_index = spr_gabi;
	
		var left, right, up, down, dash, shoot, s1, s2, s3, s4;
		left = keyboard_check(ord("A"));
		right = keyboard_check(ord("D"));
		up = keyboard_check(ord("W"));
		down = keyboard_check(ord("S"));
		dash = mouse_check_button_pressed(mb_right);
		shoot = mouse_check_button_pressed(mb_left);
		s1 = keyboard_check_pressed(ord("1")) || keyboard_check_pressed(ord("Z"));
		s2 = keyboard_check_pressed(ord("2")) || keyboard_check_pressed(ord("X"));
		s3 = keyboard_check_pressed(ord("3")) || keyboard_check_pressed(ord("C"));
		s4 = keyboard_check_pressed(ord("4")) || keyboard_check_pressed(ord("V"));
	
		var movex = right - left;
		var movey = down - up;
		
		hveloc = movex * spd;
		
		if (hveloc = 0) and (vveloc = 0) {
		sprite_index = spr_gabistill;
		}
		
		if place_meeting(x + hveloc, y, oBarreiraParent){
		while !place_meeting(x + sign(hveloc), y, oBarreiraParent){
		x+=sign(hveloc);
		}
		hveloc = 0;
		}
		x += hveloc;
		
		vveloc = movey * spd;
		
		if place_meeting(x,y + vveloc, oBarreiraParent){
		while !place_meeting(x,y + sign(vveloc), oBarreiraParent){
		y+=sign(vveloc);
		}
		vveloc = 0;
		}
		y += vveloc;
		
		
		var dic = floor(point_direction(x,y,mouse_x,mouse_y)/90);
		
		switch(dic){
		case 0: image_xscale = 1;break;
		case 1: image_xscale = -1;break;
		case 2: image_xscale = -1;break;
		case 3: image_xscale = 1;break;
		}
		
		
		
		if dash and (alarm[1] <= 0) {
		alarm[0] = 20;
		alarm[1] = 120;
		dash_dir = point_direction(x, y, mouse_x, mouse_y);
		estado = scr_player_dash;
		audio_play_sound(choose(snd_dash1,snd_dash2,snd_dash3),1,0)
		}
	
		if shoot and (alarm[2] <= 0) and (dead == false) {
		alarm[2] = 15;
		var pow = instance_create_layer(x, y, "Instances", oMagShotInf);
		pow.direction = point_direction(x, y, mouse_x, mouse_y+random_range(-0.5, 0.5));
		pow.image_angle = point_direction(x, y, mouse_x, mouse_y+random_range(-0.5, 0.5));
		pow.speed = 10;
	
		var pow1 = instance_create_layer(x, y, "Instances", oMagShotInf);
		pow1.direction = point_direction(x, y, mouse_x+25, mouse_y+random_range(-0.5, 0.5));
		pow1.image_angle = point_direction(x, y, mouse_x+25, mouse_y+random_range(-0.5, 0.5));
		pow1.speed = 10;
	
		var pow2 = instance_create_layer(x, y, "Instances", oMagShotInf);
		pow2.direction = point_direction(x, y, mouse_x-25, mouse_y+random_range(-0.5, 0.5));
		pow2.image_angle = point_direction(x, y, mouse_x-25, mouse_y+random_range(-0.5, 0.5));
		pow2.speed = 10;
		}
	
		if s1 and (skill1 <= 0) {
		actvi1 = true;
		alarm[3] = 60;
		}

		if s2 and (skill2 <= 0) and (!instance_exists(oWheelDisc)) {
		actvi2 = true;
		}
		if actvi1 = true {
			if irandom_range(0,10) < 5 {
				var shot = instance_create_layer(x+10, y+irandom_range(-8, 8), "Instances", oMagShotInf);
				shot.direction = point_direction(x, y, mouse_x, mouse_y+random_range(-2, 2));
				shot.image_angle = point_direction(x, y, mouse_x, mouse_y+random_range(-2, 2));
				shot.speed = 10;
			}
		}
		if actvi2 = true {
		var bumer = instance_create_layer(x + 5, y+30, "Instances", oWheelDisc);
		bumer.speed = 8;
		bumer.direction = point_direction(x, y, mouse_x, mouse_y);
		actvi2 = false;
		skill2 = 30;
		}

	}

	function scr_player_boss2_hit(){
		if alarm[4] > 0 {
			hveloc = lengthdir_x(3,empurra_dir);
			vveloc = lengthdir_y(3,empurra_dir);
	
			if place_meeting(x + hveloc, y, oBarreiraParent){
			while !place_meeting(x + sign(hveloc), y, oBarreiraParent){
			x+=sign(hveloc);
			}
			hveloc = 0;
			}
			x += hveloc;
		
			if place_meeting(x,y + vveloc, oBarreiraParent){
			while !place_meeting(x,y + sign(vveloc), oBarreiraParent){
			y+=sign(vveloc);
			}
			vveloc = 0;
			}
			y += vveloc;
		}else{
			estado = scr_player_boss2;
		}
	}

	function scr_player_boss2_ded(){
		sprite_index = spr_gabidead;
		if y < dead_yaxis {
		y += 0.05;
		}
	}
#endregion