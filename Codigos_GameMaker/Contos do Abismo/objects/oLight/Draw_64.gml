/// @description Insert description here
// You can write your code in this editor

if oAllan.visi = false {
	switch(oAllan.flash){
		case true: draw_sprite_ext(spr_skill1,0,40,550,1,1,0,c_white,1);break;
		case false: if oAllan.alarm[5] <= 0 {
						draw_sprite_ext(spr_skill1,1,40,550,1,1,0,c_white,1);
					}else{
					draw_sprite_ext(spr_skill1,2,40,550,1,1,0,c_white,1);
					}
	}
	if oAllan.alarm[4] <= 0 {
		draw_sprite_ext(spr_skill2,0,180,550,1,1,0,c_white,1);
	}else{
		draw_sprite_ext(spr_skill2,1,180,550,1,1,0,c_white,1);
	}
}else{
	draw_sprite_ext(spr_skill1,2,40,550,1,1,0,c_white,1);
	if oAllan.alarm[4] <= 0 {
		draw_sprite_ext(spr_skill2,0,180,550,1,1,0,c_white,1);
	}else{
		draw_sprite_ext(spr_skill2,1,180,550,1,1,0,c_white,1);
	}
}
