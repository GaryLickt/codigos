/// @description Insert description here
// You can write your code in this editor
var textX = ((room_width/2));
if room_get_name(room) = "Room1" {
	draw_set_halign(fa_center);
if passou == true {
	
draw_set_font(f_bossfontBig);
draw_set_color(c_black);
draw_text(textX+2, 102, "FASE CONCLUIDA");
draw_set_color(c_white);
draw_text(textX, 100, "FASE CONCLUIDA");
draw_set_font(-1);

switch(global.level){
case 1:
	switch(global.fase){
	case 1: draw_sprite_ext(spr_menu_newskillz,0,textX, 269,1,1,0,c_white,1);break;
	}
	global.sk1 = true;break;
case 2:
	switch(global.fase){
	case 1: draw_sprite_ext(spr_menu_newskillz,1,textX, 269,1,1,0,c_white,1);break;
	}
	global.sk1 = true;break;
}

}
if yay == true {
	draw_set_font(f_bossfontBig);
draw_set_color(c_black);
draw_text(textX+2, 102, "GAME OVER!!");
draw_set_font(f_boss2gui);
draw_text(textX+2, 127, global.frases[global.fras_count]);
draw_set_color(c_white);
draw_set_font(f_bossfontBig);
draw_text(textX, 100, "GAME OVER!!");
draw_set_font(f_boss2gui);
draw_text(textX, 125, global.frases[global.fras_count]);
draw_set_font(-1);
}
draw_set_halign(-1);
}