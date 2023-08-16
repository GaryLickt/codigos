#region Fases normais
var textX = (display_get_gui_width()/2)-80;

if room_get_name(room) = "RoomBoss1" {
	if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
		draw_sprite(spr_healthbar_side,0,28,60-32)
		var Xsao = 30;
		for(var i = 0;i<160;i++){
			draw_sprite(spr_healthbar_center,0,Xsao, 60);
			Xsao += 2;
		}
		draw_sprite(spr_healthbar_sidel,0,350,60)
	
		draw_set_halign(fa_left);
		if oBossMarco.stage = 1 {
			
			draw_set_font(f_bossfont);
			draw_text(62,30,"Ka.To.Ta [Modelo FINAL.py]")
			draw_set_font(-1);
		}else if oBossMarco.stage = 2 {
			draw_set_font(f_bossfont);
			draw_text(62,30,"Ka.To.Ta [Modelo FINAL_2.py]")
			draw_set_font(-1);
		}
		draw_set_halign(-1);
			// DESENHA A PARTE DE TRAZ DA BARRA
		var vazioX = 30;
		for(var i = 0; i<total;i++){
			draw_sprite(spr_cinzabarra,0,vazioX, 68)
			vazioX += 1;
		}
		var vX = 32;
		for(var i = 0; i<(total-4);i++){
			draw_sprite(spr_fundobarra,0,vX, 68)
			vX += 1;
		}
		healthbar_draw_ext(32,60,oBossMarco.hp,spr_barra,true,oBossMarco.extra_hp, spr_barraescudo);
	}
}
if room_get_name(room) = "RoomBoss2" {
// Barra de Vida do Jogador
	if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
			// DESENHA A PARTE DE TRAZ DA BARRA
		var vazioX = 30;
		for(var i = 0; i<total;i++){
			draw_sprite(spr_cinzabarra,0,vazioX, 108)
			vazioX += 1;
		}
		var vX = 32;
		for(var i = 0; i<(total-4);i++){
			draw_sprite(spr_fundobarra,0,vX, 108)
			vX += 1;
		}
		healthbar_draw_ext(32,100,oGabiBoss2.hp*25,spr_barra,false,5, spr_barraescudo);
		draw_set_font(f_boss2gui);
		draw_set_halign(fa_center);
		draw_text(125/2,100,string(oGabiBoss2.hp) + " / 5")
		draw_set_font(-1);
		draw_set_halign(-1);
		
		// DESENHA A BARRA DE VIDA DO BOSS
		
		var vaX = 480;
		for(var i = 0; i<total2;i++){
			draw_sprite(spr_cinzabarra,0,vaX, 78)
			vaX += 1;
		}
		var viX = 482;
		for(var i = 0; i<(total2-4);i++){
			draw_sprite(spr_fundobarra,0,viX, 78)
			viX += 1;
		}
		healthbar_draw_ext(482,70,oBossShadow.hp,spr_barra,false,5, spr_barraescudo);
		draw_set_font(f_boss2gui);
		draw_set_halign(fa_center);
		if oBossShadow.stage <= 2 {
		draw_text(482+(total2-4)/2,100,"Nathan - O Dono da Boca")
		}else if oBossShadow.stage = 3 {
		draw_text(482+(total2-4)/2,100,"3l# n40 d#vE m0rR3r aG0rA")
		}else if oBossShadow.stage = 4 {
		draw_text(482+(total2-4)/2,100,"Draco - Forma Demonio Virtual")
		}
		draw_set_font(-1);
		draw_set_halign(-1);
	}
}

#endregion

if room_get_name(room) = "RoomSelector"{
	if !instance_exists(oTransicao) and !instance_exists(oTransicaoReverse) {
		var name = "";
		var corzin = c_white;
		var xpo = display_get_gui_width()/2;
		switch(oCamera.stage){
		case 1: name = "Fabrica Chocante";corzin = c_yellow;break;
		case 2: name = "Cidade Caotica";corzin = c_dkgray;break;
		case 3: name = "Pais do Fogo";corzin = c_red;break;
		case 4: name = "Ilha Selvagem";corzin = c_lime;break;
		case 5: name = "Terra Dourada";corzin = c_orange;break;
		}

		if oMainControl.level_map[# oCamera.stage-1, 0] >= 1 {
			
			draw_set_font(f_levelselector);
			draw_set_halign(fa_center);
			draw_set_color(corzin);
			draw_text(xpo+2,62,name);
			draw_set_color(c_white);
			draw_text(xpo,60,name);
			draw_set_halign(-1);
			draw_set_font(-1);
		}else{
			
			draw_set_font(f_levelselector);
			draw_set_halign(fa_center);
			draw_set_color(c_black);
			draw_text(xpo+2,62,"???");
			draw_set_color(c_white);
			draw_text(xpo,60,"???");
			draw_set_halign(-1);
			draw_set_font(-1);
		}
	}
}