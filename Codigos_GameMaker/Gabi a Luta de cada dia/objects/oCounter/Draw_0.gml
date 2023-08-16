/// @description Insert description here
// You can write your code in this editor
var posX = 356;
var posY = 34;

var hposX = 639;

draw_set_halign(fa_center);
draw_set_font(f_bossfontBig);
draw_set_color(c_black)
draw_text(posX+2,posY+2,tempo);
draw_set_font(f_bossfont);
switch(oMainConquistas.qual_desafio){
case "afogados":
	draw_text(hposX+2,posY+2,"maior tempo: " + string(global.debaixodaguatempo));break;
case "distorcido":
	draw_text(hposX+2,posY+2,"maior tempo: " + string(global.distorcidotempo));break;
case "cinquentabarravinte":
	draw_text(hposX+2,posY+2,"maior tempo: " + string(global.cinquentabarravintetempo));break;
case "correnegada":
	draw_text(hposX+2,posY+2,"maior tempo: " + string(global.correnegadatempo));break;
case "chaolava":
	draw_text(hposX+2,posY+2,"maior tempo: " + string(global.chaolavatempo));break;
case "sempulo":
	draw_text(hposX+2,posY+2,"maior tempo: " + string(global.sempulotempo));break;
}
draw_set_font(f_bossfontBig);
draw_set_color(c_white)
draw_text(posX,posY,tempo);
draw_set_font(f_bossfont);
switch(oMainConquistas.qual_desafio){
case "afogados":
	draw_text(hposX,posY,"maior tempo: " + string(global.debaixodaguatempo));break;
case "distorcido":
	draw_text(hposX,posY,"maior tempo: " + string(global.distorcidotempo));break;
case "cinquentabarravinte":
	draw_text(hposX,posY,"maior tempo: " + string(global.cinquentabarravintetempo));break;
case "correnegada":
	draw_text(hposX,posY,"maior tempo: " + string(global.correnegadatempo));break;
case "chaolava":
	draw_text(hposX,posY,"maior tempo: " + string(global.chaolavatempo));break;
case "sempulo":
	draw_text(hposX,posY,"maior tempo: " + string(global.sempulotempo));break;
}
draw_set_halign(-1);
draw_set_font(-1);