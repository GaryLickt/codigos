/// @description Insert description here
// You can write your code in this editor
if (oMainControl.level_map[# oCamera.stage-1, 0] >= 1) and (oMainControl.level_map[# oCamera.stage-1, 0] < 7) {
	draw_sprite_ext(sombra,0,x,y,1.1,1.1,image_angle,c_white,1);
	draw_sprite_ext(sprite_index,image_index,x,y,1,1,image_angle,c_white,1);
}else if (oMainControl.level_map[# oCamera.stage-1, 0] = 0){
	draw_sprite_ext(sombra,0,x,y,1.1,1.1,image_angle,c_white,1);
	draw_sprite_ext(sprite_index,image_index,x,y,1,1,image_angle,c_black,1);
	draw_sprite_ext(spr_lock,0,x,y,0.5,0.5,image_angle,c_white,1);
}else if (oMainControl.level_map[# oCamera.stage-1, 0] = 7){
	draw_sprite_ext(sombra,0,x,y,1.1,1.1,image_angle,c_white,1);
	draw_sprite_ext(sprite_index,image_index,x,y,1,1,image_angle,c_gray,1);
	draw_sprite_ext(spr_complete,0,x,y,0.5,0.5,image_angle,c_white,1);	
}