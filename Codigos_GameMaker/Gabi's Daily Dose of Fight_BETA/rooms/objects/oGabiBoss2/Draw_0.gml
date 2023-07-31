draw_sprite_ext(sprite_index, -1,x, y, image_xscale, 1, angle, c_white, image_alpha);

if alarm[5] > 0 {
	if image_alpha >= 1 {
	dano_alpha = -0.05;
	}else if image_alpha <= 0 {
	dano_alpha = 0.05;
	}
	
	image_alpha += dano_alpha;
}else{
image_alpha = 1;
}

if instance_exists(oBossShadowGUN) {
draw_sprite_ext(spr_target,0,x,y,1,1,0,c_white,1);
}