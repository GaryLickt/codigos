/// @description Insert description here
// You can write your code in this editor
var butX = (room_width/2);

if room_get_name(room) = "Room1" {
if global.fase < 2 {
mdis = 15;
}else{
mdis = 30;
}

if (correndo == true and passou == false) and (oGabi.dead == false) {
distance += 0.02;

}

if distance >= mdis {
passou = true;
}

if distance >= (mdis - 2) {
prepassou = true;
}

if oGabi.dead == true {
	yay = true;
	oSpawner.yay = true;
}

if passou = true {
	if (!instance_exists(oButtonHome)){
		var but = instance_create_layer(butX-60,185,"Instances",oButtonHome);
		but.maxscale = 0.5;
	}
	if (!instance_exists(oButtonReset)){
		var but = instance_create_layer(butX,185,"Instances",oButtonReset);
		but.maxscale = 0.5;
	}
	if (!instance_exists(oButtonNext)){
		var but = instance_create_layer(butX+60,185,"Instances",oButtonNext);
		but.maxscale = 0.5;
	}
}

if yay = true {
	if (!instance_exists(oButtonHome)){
		var but = instance_create_layer(butX-60,185,"Instances",oButtonHome);
		but.maxscale = 0.5;
	}
	if (!instance_exists(oButtonReset)){
		var but = instance_create_layer(butX,185,"Instances",oButtonReset);
		but.maxscale = 0.5;
		global.totalmortes += 1;
		switch(global.totalmortes){
			case 5: global.cincomortes = true;break;
			case 10: global.dezmortes = true;break;
			case 20: global.vintemortes = true;break;
			case 30: global.trintamortes = true;break;
			case 50: global.cinquentamortes = true;break;
			case 100: global.cemmortes = true;break;
		}
	}
	if (oMainControl.level_map[# global.level-1, 0]) > global.fase {
		if (!instance_exists(oButtonNext)){
			var but = instance_create_layer(butX+60,185,"Instances",oButtonNext);
			but.maxscale = 0.5;
		}
	}
}

}else if room_get_name(room) = "RoomBoss1" {
var butX = (display_get_gui_width()/2);

if (oBossMarco.hp <= 0) {
	if (!instance_exists(oButtonHome)){
		var but = instance_create_layer(butX-60,382,"Instances",oButtonHome);
		but.maxscale = 1;
	}
	if (!instance_exists(oButtonReset)){
		var but = instance_create_layer(butX,382,"Instances",oButtonReset);
		but.maxscale = 1;
	}
	if (!instance_exists(oButtonNext)){
		var but = instance_create_layer(butX+60,382,"Instances",oButtonNext);
		but.maxscale = 1;
		switch(global.level){
			case 1: global.primeiromundo = true;break;
			case 2: global.segundomundo = true;break;
			case 3: global.terceiromundo = true;break;
			case 4: global.quartomundo = true;break;
			case 5: global.quintomundo = true;break;
		}
	}
}

if (oGabiBoss1.dead = true) {
	if (!instance_exists(oButtonHome)){
		var but = instance_create_layer(butX-120,382,"Instances",oButtonHome);
		but.maxscale = 1;
	}
	if (!instance_exists(oButtonReset)){
		var but = instance_create_layer(butX,382,"Instances",oButtonReset);
		but.maxscale = 1;
	}
	if (oMainControl.level_map[# global.level-1, 0]) > global.fase {
		if (!instance_exists(oButtonNext)){
			var but = instance_create_layer(butX+120,382,"Instances",oButtonNext);
			but.maxscale = 1;
		}
	}
}
}

depth = -1000;
total = clamp(total,ilife,maxlife);