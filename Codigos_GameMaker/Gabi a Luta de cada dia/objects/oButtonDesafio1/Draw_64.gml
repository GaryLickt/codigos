/// @description Insert description here
// You can write your code in this editor
if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
if place_meeting(x,y,oMouseCollision){
	if sprite_index != spr_button { 
	var tx = 1021;
	var ty = 293;
	var hx = 1001;
	var hy = 433;
	var x1 = tx-310;
	var x2 = tx+310;
	var y1 = ty-100;
	var y2 = hy+100;
	
draw_rectangle_color(x1-4,y1-4,x2+4,y2+4,c_white,c_white,c_white,c_white,false);
draw_rectangle_color(x1,y1,x2,y2,c_black,c_black,c_black,c_black,false);
draw_set_font(f_menu);
draw_set_halign(fa_center);
draw_set_color(c_black);
draw_text(tx+2,ty+2,"Desafio: Tudo de uma só vez")
draw_set_color(c_white);
draw_text(tx,ty,"Desafio: Tudo de uma só vez")

draw_set_font(f_bossfontBig);
draw_set_color(c_black);
draw_text(tx+2,ty+100,"todos os seus inimigos em um unico lugar")
draw_text(hx+2,hy+2,"Maior tempo (em segundos):" + string(global.cinquentabarravintetempo))
draw_set_color(c_white);
draw_text(tx,ty+98,"todos os seus inimigos em um unico lugar")
draw_text(hx,hy,"Maior tempo (em segundos):" + string(global.cinquentabarravintetempo))
draw_set_font(-1);
draw_set_halign(-1);
}else{
	var tx = 1021;
		var ty = 293;
		var hx = 1001;
		var hy = 433;
		var x1 = tx-300;
		var x2 = tx+300;
		var y1 = ty-100;
		var y2 = hy+100;
	
		draw_rectangle_color(x1-4,y1-4,x2+4,y2+4,c_white,c_white,c_white,c_white,false);
		draw_rectangle_color(x1,y1,x2,y2,c_black,c_black,c_black,c_black,false);
		draw_set_font(f_menu);
		draw_set_halign(fa_center);
		draw_set_color(c_black);
		draw_text(tx+2,ty+2,"Desafio Bloqueado")
		draw_set_color(c_white);
		draw_text(tx,ty,"Desafio Bloqueado")

		draw_set_font(f_bossfontBig);
		draw_set_color(c_black);
		draw_text(tx+2,ty+100,"Desafio disponivel somente após zerar o jogo")
		draw_set_color(c_white);
		draw_text(tx,ty+98,"Desafio disponivel somente após zerar o jogo")
		draw_set_font(-1);
		draw_set_halign(-1);
	}
}
}