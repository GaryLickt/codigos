// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function healthbar_draw_ext(x_,y_,amount_,sprite_,extra_bar_, extra_amount_, extra_sprite_){
	// CASO TENHA UMA BARRA DESENHA AMBAS, CASO CONTRARIO DESENHA SOMENTE A PRIMEIRA BARRA
	if extra_bar_ = true {
		var posX = x_;
		var extra_posX = 0;
		for(var i = 0; i<amount_;i++;){
			draw_sprite(sprite_,0,posX, y_)
			posX += 1
		}
		extra_posX = posX;
		y_ += 8;
		for(var i = 0; i<extra_amount_;i++;){
			draw_sprite(extra_sprite_,0,extra_posX, y_)
			extra_posX += 1;
		}
	}else{
		var posX = x_;
		var extra_posX = 0;
		for(var i = 0; i<amount_;i++;){
			draw_sprite(sprite_,0,posX, y_)
			posX += 1
		}
	}
}