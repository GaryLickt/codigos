#region Fases normais
var textX = (display_get_gui_width()/2)-80;

if room_get_name(room) = "Room1" {
draw_text(20, 10, oGabi.caos);
draw_text(20, 30, distance);

draw_text(20, 80, oGabi.skill1);
draw_text(20, 100, oGabi.skill2);
draw_text(20, 120, oGabi.skill3);
draw_text(20, 140, oGabi.skill4);

draw_text(20, 200, global.level);
draw_text(20, 220, global.fase);
draw_text(40, 200, global.highlevel);

var ent = global.level-1;

draw_text(40, 220, oMainControl.level_map[# ent, 0]);

if passou == true {
	
draw_set_font(f_bossfontBig);
draw_text(textX, 150, "FASE CONCLUIDA!!");
draw_set_font(-1);

}
if yay == true {
	draw_set_font(f_bossfontBig);
draw_text(textX, 150, "GAME OVER!!");
draw_set_font(-1);

}
}
if room_get_name(room) = "RoomBoss1" {
	draw_sprite(spr_healthbar_side,0,28,60-32)
	var Xsao = 30;
	for(var i = 0;i<160;i++){
		draw_sprite(spr_healthbar_center,0,Xsao, 60);
		Xsao += 2;
	}
	draw_sprite(spr_healthbar_sidel,0,350,60)
	
	
	if oBossMarco.stage = 1 {
		draw_set_font(f_bossfont);
		draw_text(62,30,"Ka.To.Ta [Modelo FINAL.py]")
		draw_set_font(-1);
	}else if oBossMarco.stage = 2 {
		draw_set_font(f_bossfont);
		draw_text(32,30,"Ka.To.Ta [Modelo FINAL_2.py]")
		draw_set_font(-1);
	}
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

if oBossMarco.hp <= 0 {
draw_set_font(f_bossfontBig);
draw_text(textX, 250, "FASE CONCLUIDA!!");
draw_set_font(-1);

}
if oGabiBoss1.dead = true {
	draw_set_font(f_bossfontBig);
draw_text(textX, 250, "GAME OVER!!");
draw_set_font(-1);

}
}
if room_get_name(room) = "RoomBoss2" {
// Barra de Vida do Jogador
	
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
}

#endregion

if room_get_name(room) = "RoomSelector"{
	var name = "";
	var xpo = display_get_gui_width()/2;
	switch(oCamera.stage){
	case 1: name = "Fabrica Chocante";break;
	case 2: name = "Cidade Caotica";break;
	case 3: name = "Pais do Fogo";break;
	case 4: name = "Ilha Selvagem";break;
	case 5: name = "Terra Dourada";break;
	}

	if oMainControl.level_map[# oCamera.stage-1, 0] >= 1 {
		draw_set_font(f_levelselector);
		draw_set_halign(fa_center);
		draw_text(xpo,60,name);
		draw_set_halign(-1);
		draw_set_font(-1);
	}else{
		draw_set_font(f_levelselector);
		draw_set_halign(fa_center);
		draw_text(xpo,60,"???");
		draw_set_halign(-1);
		draw_set_font(-1);
	}
}