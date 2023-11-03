/// @description Insert description here
// You can write your code in this editor
if surface_exists(surf) {
	surface_set_target(surf);
	if oAllan.visi = false {
		draw_set_color(c_black);
		draw_set_alpha(0.98);
		draw_rectangle(0,0,room_width,room_height,false);
		draw_set_alpha(1);
		draw_set_color(c_white);
		

		if (oAllan.flash = true) and (pisca = false) {
			gpu_set_blendmode(bm_subtract);
			draw_sprite_ext(spr_flashlight,0,oAllan.x,oAllan.y,1+treme,1+treme,ang,c_white,1);
			if instance_exists(oSavePoint){
			draw_sprite_ext(spr_miniflashlight,0,oSavePoint.x,oSavePoint.ypos-16,1,1,ang,c_white,1);
			}
			gpu_set_blendmode(bm_normal);
		}
		
	}else if oAllan.visi = true {
		
		draw_set_color(c_purple);
		draw_set_alpha(0.8);
		draw_rectangle(0,0,room_width,room_height,false);
		draw_set_color(c_black);
		draw_set_alpha(0.9);
		draw_rectangle(0,0,room_width,room_height,false);
		draw_set_alpha(1);
		draw_set_color(c_white);

		draw_set_font(f_visioncounter);
		draw_set_color(c_black);
		draw_text(oAllan.x-6,oAllan.y-156,floor(oAllan.tempo_maximo))
		draw_set_color(c_purple);
		draw_text(oAllan.x-8,oAllan.y-158,floor(oAllan.tempo_maximo))
		draw_set_font(-1);
		draw_set_color(c_white);
		
		gpu_set_blendmode(bm_subtract);
		draw_sprite_ext(spr_flashcore,0,oAllan.x,oAllan.y,1+treme,1+treme,ang,c_white,1);
		if instance_exists(oSavePoint){
		draw_sprite_ext(spr_miniflashcore,0,oSavePoint.x,oSavePoint.ypos-16,1,1,ang,c_white,1);
		}
		gpu_set_blendmode(bm_normal);
		
		draw_sprite_ext(spr_flashcore,0,oAllan.x,oAllan.y,1+treme,1+treme,ang,c_purple,0.6);
		if instance_exists(oSavePoint){
		draw_sprite_ext(spr_miniflashcore,0,oSavePoint.x,oSavePoint.ypos-16,1,1,ang,c_purple,0.6);
		}
	}

surface_reset_target();
}else{
surf = surface_create(room_width,room_height);
}
draw_surface(surf,0,0);
