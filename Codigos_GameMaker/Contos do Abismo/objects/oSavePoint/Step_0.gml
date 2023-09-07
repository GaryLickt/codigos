/// @description Insert description here
// You can write your code in this editor
visao = oAllan.visi;

depth = -ypos;
if visao {
sprite_index = spr_savecursed;
}else{
sprite_index = spr_save;
}

ypos = ypos + sin(timer * 0.03) * 0.2;

timer ++;


