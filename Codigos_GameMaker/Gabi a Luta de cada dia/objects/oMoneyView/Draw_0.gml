/// @description Insert description here
// You can write your code in this editor
draw_self();

if oMainControl.money > 0 {
draw_set_font(f_menu);
draw_set_color(c_black);
draw_text(x-4,y+4,"$ " + string(oMainControl.money));
draw_text(x-2,y+2,"$ " + string(oMainControl.money));
draw_set_color(c_white);
draw_text(x,y,"$ " + string(oMainControl.money));
draw_set_font(-1);
}else{
draw_set_font(f_menu);
draw_set_color(c_black);
draw_text(x-4,y+4,"Tu ta pobre meu caro");
draw_text(x-2,y+2,"Tu ta pobre meu caro");
draw_set_color(c_white);
draw_text(x,y,"Tu ta pobre meu caro");
draw_set_font(-1);
}

