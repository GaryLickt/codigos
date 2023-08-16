if ((startX != 0) and (startY!=0)) {
	if instance_exists(oTeddy) and (global.teddyroom != 0) {
		instance_destroy(oTeddy);
	}
	if instance_exists(oBanni) and (global.banniroom != 0) {
		instance_destroy(oBanni);
	}
	if instance_exists(oSasha) and (global.sasharoom != 0) {
		instance_destroy(oSasha);
	}
	if instance_exists(oFelix) and (global.felixroom != 0) {
		instance_destroy(oFelix);
	}
	
	switch(room) {
		case global.teddyroom: instance_create_layer(global.teddy_xpos,global.teddy_ypos,"Instances",oTeddy);break;
		case global.banniroom: instance_create_layer(global.banni_xpos,global.banni_ypos,"Instances",oBanni);break;
		case global.sasharoom: instance_create_layer(global.sasha_xpos,global.sasha_ypos,"Instances",oSasha);break;
		case global.felixroom: instance_create_layer(global.felix_xpos,global.felix_ypos,"Instances",oFelix);break;
	}

	
	
	if instance_exists(oAllan){
		oAllan.x = startX;
		oAllan.y = startY;
		oAllan.flash = lanterna_on;
		oAllan.visi = visao_on;
		oAllan.tempo_maximo = visao_tempo;
		
		if ta_fudido = true {
			instance_destroy(bixu_ruim);
			alarm[0] = distancia_anticu;
		}else{
		
		}
		
		
		oCamera.x = startX;
		oCamera.y = startY;
	}
	startX = 0;
	startY = 0;
}
