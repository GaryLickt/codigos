/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) = "RoomMenu" {
if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
if oDoly.sprite_index = spr_doly {
draw_set_halign(fa_center);
draw_set_color(c_black);
draw_set_font(f_menu);
draw_text((room_width/2)+2,92,"Gabi: A Luta de Cada Dia");
draw_set_color(c_white);
draw_text((room_width/2),90,"Gabi: A Luta de Cada Dia");
draw_set_halign(-1);
draw_set_font(-1);
}

if oDoly.sprite_index = spr_curseddoly {
draw_set_halign(fa_center);
draw_set_color(c_black);
draw_set_font(f_menu);
draw_text((room_width/2)+2,92,text[loc]);
draw_set_color(c_white);
draw_text((room_width/2),90,text[loc]);
draw_set_halign(-1);
draw_set_font(-1);
}
}
}
	
if room_get_name(room) = "RoomMenuDesafio" {
if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
draw_set_halign(fa_center);
draw_set_color(c_black);
draw_set_font(f_menu);
draw_text((room_width/2)+2,92,"Desafios");
draw_set_color(c_white);
draw_text((room_width/2),90,"Desafios");
draw_set_halign(-1);
draw_set_font(-1);

}
}