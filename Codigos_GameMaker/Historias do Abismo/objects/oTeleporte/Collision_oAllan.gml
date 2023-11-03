/// @description Insert description here
// You can write your code in this editor

#region Seta as posições dos monstros
if instance_exists(oTeddy) and (room_get_name(room) = "Room3"){
global.teddy_xpos = oTeddy.x;
global.teddy_ypos = oTeddy.y;
global.teddyroom = room;
}
if instance_exists(oBanni){
global.banni_xpos = oBanni.x;
global.banni_ypos = oBanni.y;
global.banniroom = room;
}
if instance_exists(oSasha){
global.sasha_xpos = oSasha.x;
global.sasha_ypos = oSasha.y;
global.sasharoom = room;
}
if instance_exists(oFelix){
global.felix_xpos = oFelix.x;
global.felix_ypos = oFelix.y;
global.felixroom = room;
}
#endregion

oTeleportControle.startX = posX;
oTeleportControle.startY = posY;
room_goto(sala);

if pode_seguir = true {
	if other.detect = true {
		oTeleportControle.ta_fudido = true;
		oTeleportControle.spawnX = posX;
		oTeleportControle.spawnY = posY;
		var _bixu = 0;
			for (var _i = 0;_i<instance_number(oMascotParent);_i++){
				var _b = instance_find(oMascotParent,_i);
				if _b.puto = true {
					_bixu = _b;
					switch(_b) {
					case oTeddy.id: oTeleportControle.bixu_ruim = oTeddy;break;
					case oBanni.id: oTeleportControle.bixu_ruim = oBanni;break;
					case oSasha.id: oTeleportControle.bixu_ruim = oSasha;break;
					case oFelix.id: oTeleportControle.bixu_ruim = oFelix;break;
					}
				}
			}
		var _dist = floor(point_distance(other.x, other.y, _bixu.x, _bixu.y)/60);
		oTeleportControle.distancia_anticu = _dist*60;
	}
}

oTeleportControle.lanterna_on = other.flash;
oTeleportControle.visao_on = other.visi;
oTeleportControle.visao_tempo = other.tempo_maximo;
