if room_get_name(room) != "RoomBoss1" {
draw_text(20, 10, oGabi.caos);
draw_text(20, 30, distance);

draw_text(20, 80, oGabi.skill1);
draw_text(20, 100, oGabi.skill2);
draw_text(20, 120, oGabi.skill3);
draw_text(20, 140, oGabi.skill4);

if passou == true {
draw_text((room_width/2)-20, 50, "FASE CONCLUIDA!!");
}
if yay == true {
draw_text((room_width/2)-20, 50, "GAME OVER!!");
draw_text((room_width/2)-20, 100, "Aperte ENTER para tentar novamente");
}
}else {
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
}
if oGabiBoss1.dead = true {
	draw_set_font(f_bossfont);
draw_text((room_width/2)-20, 250, "GAME OVER!!");
draw_text((room_width/2)-20, 300, "Aperte ENTER para tentar novamente");
draw_set_font(-1);
}
}